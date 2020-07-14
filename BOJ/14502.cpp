#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define p pair<int, int>
#define MAX_LEN 8

using namespace std;

int N, M;
int map[MAX_LEN][MAX_LEN];
int updated_map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[] = {0, -1, 0 , 1}, dy[] = {-1, 0 , 1, 0};
vector<p> viruses;

void init() {
    memset(updated_map, 0, sizeof(updated_map));
    memset(visited, 0, sizeof(visited));
}

void getUpdatedMap(vector<p>& walls) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            updated_map[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < walls.size(); i++) {
        int x = walls[i].first;
        int y = walls[i].second;
        updated_map[x][y] = 1;
    }
}
int countSafeArea() {
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (updated_map[i][j] == 0) answer++;
        }
    }
    return answer;
}

void bfs() {
    queue<p> q;
    for (int i = 0; i < viruses.size(); i++) {
        p virus = viruses[i];
        visited[virus.first][virus.second] = true;
        q.push(virus);
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (visited[nx][ny]) continue;
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (updated_map[nx][ny] > 0) continue;

                visited[nx][ny] = true;
                updated_map[nx][ny] = 2;
                q.push(make_pair(nx, ny)); 
            }
        }
    }
}

int solve() {
    int answer = 0;
    int len = N * M;
    for (int i = 0; i < len - 2; i++) {
        if (map[i / M][i % M] != 0) continue;
        for (int j = i + 1; j < len - 1; j++) {
            if (map[j / M][j % M] != 0) continue;
            for (int k = j + 1; k < len; k++) {
                if (map[k / M][k % M] != 0) continue;
                vector<p> walls;
                walls.push_back(make_pair(i / M, i % M));
                walls.push_back(make_pair(j / M, j % M));
                walls.push_back(make_pair(k / M, k % M));
                getUpdatedMap(walls);
                bfs();
                int updated = countSafeArea();
                answer = answer > updated ? answer : updated;
                init();
                walls.clear();
            }
        }
    }
    return answer;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) viruses.push_back(make_pair(i, j));
        }
    }
    printf("%d\n", solve());
    return 0;
}