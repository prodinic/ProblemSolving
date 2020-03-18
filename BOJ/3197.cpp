#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define MAX_LEN 1501
#define INF 987654321
#define pp pair<int, pair<int, int > >

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
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            if (map[i][j] == '.' || map[i][j] == 'L') ice[i][j] = 1; 
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || x >= R || y < 0 || y >= C) continue;
                if ((map[x][y] == '.' || map[x][y] == 'L') && map[i][j] == 'X' && visited[i][j] == false) {

                    visited[i][j] = true;
                    q.push(make_pair(2, make_pair(i, j)));
                }
            }
        }
    }

    while(!q.empty()) {

        int len = q.size();

        while(len--) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int day = q.front().first;
            q.pop();

            if (days < day) days = day; // 얼음이 모두 녹기 까지 걸리는 일수를 갱신합니다. 

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (ice[nx][ny] != 0 && ice[nx][ny] <= day) continue;          

                ice[nx][ny] = day + 1;      
                q.push(make_pair((day + 1), make_pair(nx, ny)));      
            }
        }
    }

    memset(visited, false, sizeof(visited));
}

void bfs() {
    // 설명 : 이분 탐색을 이용하여 탐색합니다.

    pair<int, int > from, to;
    from = make_pair(v[0].first, v[0].second);
    to = make_pair(v[1].first, v[1].second);
    _left = 0;
    _right = days;

    while (_left <= _right) {
        int mid = (_left + _right) / 2;
        bool flag = false;

        priority_queue<pp> pq;
       
        visited[from.first][from.second] = true;
        pq.push(make_pair(0, from));

        while(!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int step = -pq.top().first;
            pq.pop();

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
                pq.push(make_pair(-(step + 1), make_pair(nx, ny)));
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