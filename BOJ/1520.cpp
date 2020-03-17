#include <iostream>
#include <vector>
#define MAX_LEN 501
#define ll long long int

using namespace std; 

int M, N;
int map[MAX_LEN][MAX_LEN];
ll dp[MAX_LEN][MAX_LEN];
ll answer = 0;
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

void printAll() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
void init () {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            dp[i][j] = -1;
        }
    }
}

int dfs(int x, int y) {

    if (x == M - 1 && y == N - 1) { // return -1 if it gets to destination
        return 1;
    }

    if (dp[x][y] == -1) {   // check the case which hasn't been visited 
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (map[x][y] <= map[nx][ny]) continue;

            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    init();
    cout << dfs(0, 0) << endl;
return 0;
}