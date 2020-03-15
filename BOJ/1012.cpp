#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define MAX_LEN 51

using namespace std;

int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int T, M, N, K;
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int answer = 0;

void init() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = 0;
        }
    }
}
void bfs() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (visited[i][j] == true || map[i][j] == 0) continue;  // pass the case where it is already visited or there is no cabbage

            queue<pair<int, int > > q;

            visited[i][j] = true;
            q.push(make_pair(i, j));

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;   // out of range
                    if (visited[nx][ny]) continue;  // already visited
                    if (map[nx][ny] == 0) continue; // empty space

                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }

            answer++;
        }
    }

    cout << answer << endl;
}

int main() {

    int a, b;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;

        for (int j = 0; j < K; j++) {
            cin >> a >> b;
            map[b][a] = 1;
        }

        bfs();
        memset(map, false, sizeof(map));
        memset(visited, false, sizeof(visited));
        answer = 0;
    } 



    return 0;
}