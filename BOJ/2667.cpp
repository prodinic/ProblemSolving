#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_LEN 25

using namespace std;

int N;
char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
vector<int > answer;
int dx[] = {0, -1, 0 , 1}, dy[] = {-1, 0, 1, 0};

bool compare(int a, int b) {
    if (a < b) return true;
    else return false;
}
void bfs(int x, int y) {

    queue<pair<int, int > > q;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    int cnt = 0;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] == '0') continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }

    answer.push_back(cnt);
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            cin >> map[i][j];
        }
    }

    // search
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (map[i][j] == '1' && visited[i][j] != true) bfs(i, j); 
        }
    }

    sort(answer.begin(), answer.end(), compare);
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }


    
    return 0;
}