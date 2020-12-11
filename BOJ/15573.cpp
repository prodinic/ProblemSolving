#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX_LEN 1000
#define MAX_NUM 1000000
#define p pair<int, int>

using namespace std;

int N, M, K;
int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int D = MAX_NUM, dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int init(int d, queue<p> &q) {

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (map[0][i] <= d && visited[0][i] == false) {
            cnt++;
            visited[0][i] = true;
            q.push(make_pair(0, i));
        }
    }

    for (int i = 0; i < N; i++) {
        if (map[i][0] <= d && visited[i][0] == false) {
            cnt++;
            visited[i][0] = true;
            q.push(make_pair(i, 0));
        }
    }

    for (int i = 0; i < N; i++) {
        if (map[i][M - 1] <= d && visited[i][M - 1] == false) {
            cnt++;
            visited[i][M - 1] = true;
            q.push(make_pair(i, M - 1));
        }
    }

    return cnt;
}

int bfs(int d) {

    queue<p> q;
    int cnt = init(d, q);
    if (cnt >= K) return cnt;
    else {
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visited[nx][ny]) continue;
                if (map[nx][ny] > d) continue;

                cnt++;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return cnt;
}

void solve() {

    int from = 1, to = MAX_NUM;
    while(from < to) {
        memset(visited, false, sizeof(visited));
        int mid = (from + to) / 2;
        int k = bfs(mid);
        if (k >= K) {
            D = mid;
            to = mid;
        }
        else from = mid + 1;    
    }
    printf("%d\n", D);
}

int main() {

    memset(map, 0, sizeof(map));
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    solve();

    return 0;
}