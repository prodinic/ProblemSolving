#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#define MAX_LEN 1001
#define pp pair<int, pair<int, int > >
#define INF 987654321

using namespace std;

int M, N;
int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
queue<pp> q;
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int answer = -1;

bool isAvailable() {
    // description : check all the tomatoes if it is ripen or not
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {   // check there is no ripen apple
                return false;
            }
        }
    }

    return true;
}

void bfs() {

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int step = q.front().first;

        q.pop();

        if (answer < step) answer = step;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] != 0) continue; // empty space or already ripen apple
            if (visited[nx][ny]) continue;  // already visited

            visited[nx][ny] = true;
            map[nx][ny] = 1;
            q.push(make_pair(step + 1, make_pair(nx, ny)));
        }
    }
 
    if (isAvailable()) cout << answer << endl;
    else cout << -1 << endl;
    return;
}

int main() {

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            cin >> map[i][j];
            if (map[i][j] == 1) {
                visited[i][j] = true;
                q.push(make_pair(0, make_pair(i, j)));
            }
        }
    }

    if (q.size() == N * M) cout << 0 << endl;
    else if (q.size() == 0) cout << -1 << endl;
    else {
        bfs();
    }


    return 0;
}