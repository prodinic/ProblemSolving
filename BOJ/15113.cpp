#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAX_NUM 31
#define ppp pair<int, pair<char, pair<int, int> > > 

using namespace std;

int m, n; 
int dx[] = {0, -1}, dy[] = {-1, 0};
char map[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];
int the_num_of_empty_spaces = 0;
vector<pair<int, int > > Bs;
int ans = 0, filled = 0;

void printAll() {
    printf("---Map---\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("---------\n");
}
bool isPossible(int x, int y) {
    bool isAllBlue = true;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (map[i][j] == 'B' || map[i][j] == '.') continue;
            else {
                isAllBlue = false;
                break;
            }
        }
    }
    return isAllBlue;
}
void colorWithBlue(int x, int y) {

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (map[i][j] == 'B') continue;
            else if (map[i][j] == 'R') {
                continue;
            }
            else {
                map[i][j] = 'B';
            }
        }
    }
}

void countEmptySpace() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '.') the_num_of_empty_spaces++;
        }
    }
}

void init() {
    for (int i = 0; i < Bs.size(); i++) {
        int x = Bs[i].first;
        int y = Bs[i].second;
        printf("%d %d\n", x, y);
        colorWithBlue(x, y);
    }
    countEmptySpace();
    printf("the num of spaces : %d\n", the_num_of_empty_spaces);
}

void bfs(int a, int b) {

    queue<ppp> q;
    if (map[a][b] == '.') {
        if (!visited[a][b]) {
            filled++;
            visited[a][b] = true;
        }
        q.push(make_pair(filled, make_pair('R', make_pair(a, b))));
        if (isPossible(a, b)) q.push(make_pair(filled, make_pair('B', make_pair(a, b))));
    }
    else {
        q.push(make_pair(0, make_pair(map[a][b], make_pair(a, b))));
    }

    while(!q.empty()) {
        int x = q.front().second.second.first;
        int y = q.front().second.second.second;
        char stat = q.front().second.first;
        int cur_filled = q.front().first;
        q.pop();
        printf("x : %d | y : %d | stat : %c | cur_filled : %d \n", x, y, stat, cur_filled);
        if (x == 0 && y == 0 && the_num_of_empty_spaces == cur_filled) {
            ans++;
            continue;
        }
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if (stat == 'B') 
            if (map[nx][ny] == '.') {
                if (!visited[nx][ny]) {
                    filled++;
                    visited[nx][ny] = true;
                }
                printf("nx : %d | ny : %d | filled : %d\n", nx, ny, filled);
                q.push(make_pair(filled, make_pair('R', make_pair(nx, ny))));
                if (isPossible(nx, ny)) q.push(make_pair(filled, make_pair('B', make_pair(nx, ny))));
            }
            else {
                q.push(make_pair(filled, make_pair(map[nx][ny], make_pair(nx, ny))));
            }
        }
    }
}

int main() {

    memset(visited, false, sizeof(visited));
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'B') Bs.push_back(make_pair(i, j));
        }
        getchar();
    }
    init();
    printAll();
    bfs(m - 1, n - 1);
    printf("%d\n", ans);
    return 0;
}