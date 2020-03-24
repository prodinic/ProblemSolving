#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#define MAX_LEN 101

using namespace std;

int T, M, N, L, G;
int h[MAX_LEN][MAX_LEN], v[MAX_LEN][MAX_LEN];
int r[MAX_LEN][MAX_LEN] = {0, };
int dx[] = {0, 1}, dy[] = {1, 0};

void init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> r[i][j];
        }
    }
}

void bfs() {

    queue<pair<int, int > > q; 
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        int x = q.front().first; 
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (i == 0) {   // horizontal
                if (r[x][y] + h[x][y] >= r[nx][ny]) continue;
                if (r[x][y] + h[x][y] >= G) continue;

                r[nx][ny] = r[x][y] + h[x][y];
                q.push(make_pair(nx, ny));
            }
            else {  // vertical
                if (r[x][y] + v[x][y] >= r[nx][ny]) continue;
                if (r[x][y] + v[x][y] >= G) continue;

                r[nx][ny] = r[x][y] + v[x][y];
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void solve() {



}

int main() {

    cin >> T;

    while(T--) {

        cin >> M >> N >> L >> G;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N - 1; j++) {
                cin >> h[i][j];
            }
        }
        
    for (int i = 0; i < M - 1; i++) {
            for (int j = 0; j < N; j++) {
                cin >> v[i][j];
            }
        }
        
    }


    return 0;
}