#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define MAX_LEN 1501
#define INF 987654321
#define pp pair<int, pair<int, int > >
#define p pair<int, int >

using namespace std;

int R, C;
char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int ice[MAX_LEN][MAX_LEN] = {0, };
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int days = -1, answer = INF,_left, _right;
vector<pair<int, int > > v;

void printAll() {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            cout << ice[i][j];
        }
        cout << endl;
    }
}
void simulation() {
    // 설명 : 해빙 시뮬레이션을 실행합니다.

    queue<pp> q;

    // init
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {

            if (map[x][y] == '.' || map[x][y] == 'L') ice[x][y] = 1; 
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (visited[x][y]) continue;
                if ((map[x][y] == '.' || map[x][y] == 'L') && map[nx][ny] == 'X') {
                    
                    // ice[nx][ny] = 2;
                    visited[x][y] = true;
                    q.push(make_pair(1, make_pair(x, y)));
                }
            }
        }
    }

 // check all position
    while(!q.empty()) {

        int len = q.size();
        while(len--) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int day = q.front().first;
            q.pop();
            if (days < day) days = day;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (visited[nx][ny]) continue;
                if (ice[nx][ny] != 0 && ice[nx][ny] <= day) continue;          

                // is_ice_here = true;
                ice[nx][ny] = day + 1;      
                visited[nx][ny] = true;
                q.push(make_pair((day + 1), make_pair(nx, ny)));      
            }
        }
    }

    memset(visited, false, sizeof(visited));
}

void bfs() {
    // 설명 : 이분 탐색을 이용하여 탐색합니다.

    p from, to;
    from = make_pair(v[0].first, v[0].second);
    to = make_pair(v[1].first, v[1].second);
    _left = 0;
    _right = days;

    while (_left <= _right) {
        int mid = (_left + _right) / 2;
        bool flag = false;

        queue<p> q;
       
        visited[from.first][from.second] = true;
        q.push(from);

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == to.first && y == to.second) {
                flag = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (visited[nx][ny]) continue;
                if (ice[nx][ny] > mid + 1) continue;

                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }

        if (flag) {
            if (answer > mid) answer = mid;
            _right = mid - 1;
        }
        else {
            _left = mid + 1;
        }

        memset(visited, false, sizeof(visited));
    }
}

int main() {

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'L') {
                v.push_back(make_pair(i, j));
            }
        }
    }

    simulation();
    // printAll();
    bfs();

    cout << answer << endl;

    return 0;
}