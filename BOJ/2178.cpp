#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_LEN 101
#define INF 987654321

using namespace std; 

int N, M;
char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
const int dx[] = {0, -1, 0 , 1}, dy[] = {-1, 0, 1, 0};
int answer = INF;

void bfs() {

    priority_queue<pair<int, pair<int, int > > > pq;

    visited[0][0] = true;
    pq.push(make_pair(-1, make_pair(0, 0)));

    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int step = -pq.top().first;
        pq.pop();
        // cout << "x : "<<x << " | y : "<< y << " step : "<< step << endl;
        if (step < answer && (x == N - 1 && y == M - 1)) {
            answer = step;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == '0') continue;

            visited[nx][ny] = true;
            pq.push(make_pair(-(step + 1), make_pair(nx, ny)));
        }
        
    }

}
int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            cin >> map[i][j]; 
        }
    }

    bfs();
    cout << answer << endl;
    return 0;
}