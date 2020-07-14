#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#define p pair<int, int>
#define ppp pair<int, pair<int, pair<int, int > > >
#define MAX_LEN 101
#define MAX_NUM 987654321

using namespace std;

int W, H;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int stages[MAX_LEN][MAX_LEN];
vector<p> spots;

void printAll() {
    printf("---visited---\n");
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%d", stages[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}
void bfs(int src_x, int src_y, int dest_x, int dest_y) {

    int ans = MAX_NUM;
    priority_queue<ppp> pq;
    visited[src_x][src_y] = true;
    pq.push(make_pair(0, make_pair(-1, make_pair(src_x, src_y))));

    while(!pq.empty()) {
        int stage = -pq.top().first;
        int dir = pq.top().second.first;
        int x = pq.top().second.second.first;
        int y = pq.top().second.second.second;
        pq.pop();
        
        // if (stage >= ans) continue; // don't need to check
        // if (x == dest_x && y == dest_y && stage < ans) {    // update answer
        //     printf("stage : %d | dir : %d\n", stage, dir);
        //     ans = stage;
        //     continue;
        // }
        for (int next_dir = 0; next_dir < 4; next_dir++) {
            int nx = x + dx[next_dir];
            int ny = y + dy[next_dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (map[nx][ny] == '*') continue;

            if (dir == next_dir) {
                // printf("%d %d %d %d\n", nx, ny, dir, stage); 
                if (visited[nx][ny]) {
                    if (stage <= stages[nx][ny]) {
                        stages[nx][ny] = stage;
                        pq.push(make_pair(-stage, make_pair(dir, make_pair(nx, ny))));                        
                    }
                    else continue;
                }
                else {
                    stages[nx][ny] = stage;
                    visited[nx][ny] = true;
                    pq.push(make_pair(-stage, make_pair(dir, make_pair(nx, ny))));
                }
            } 
            else {
                if (dir == -1) {
                    visited[nx][ny] = true;
                    stages[nx][ny] = 0;
                    pq.push(make_pair(0, make_pair(next_dir, make_pair(nx, ny))));
                }
                else {
                    if (visited[nx][ny]) {
                        if (stage + 1 <= stages[nx][ny]) { 
                            visited[nx][ny] = stage + 1;
                            pq.push(make_pair(-(stage + 1), make_pair(next_dir, make_pair(nx, ny))));
                        }
                        else continue;
                    }
                    else {
                        stages[nx][ny] = stage + 1;
                        visited[nx][ny] = true;
                        pq.push(make_pair(-(stage + 1), make_pair(next_dir, make_pair(nx, ny))));                        
                    }
                }
            } 
        }
    }

    printf("%d\n", stages[dest_x][dest_y]);
    // printAll();
    return;
}
void solve() {

    int src_x = spots[0].first;
    int src_y = spots[0].second;
    int dest_x = spots[1].first;
    int dest_y = spots[1].second; 

    bfs(src_x, src_y, dest_x, dest_y);
}

void getSpot() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 'C') spots.push_back(make_pair(i, j));
        }
    }
}

int main() {

    memset(visited, false, sizeof(visited));
    memset(stages, 0, sizeof(stages));
    scanf("%d %d", &W, &H);
    for (int i = 0; i < H; i++) {
        scanf("%s", map[i]);
        getchar();
    }
    getSpot();
    solve();

    return 0;
}