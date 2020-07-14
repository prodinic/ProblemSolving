#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX_SIZE 501
#define MAX_NUM 987654321

using namespace std; 

int N, t, r, c;
char map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE][2];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
queue<pair<int, int > > q;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                visited[i][j][k] = MAX_NUM;
            }
        }
    }
}

int go(int x, int y, int dir) {
    int hops = 1;
    bool gotcha = false;
    int nx = x, ny = y;
    while(1) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;  // out of range
        if (map[nx][ny] == '#') {
            gotcha = true;
            break;
        }
        else hops++;
    }
    if (gotcha) {
        return hops;
    }
    else {
        return 0;
    }
}

void searchWarp(int x, int y) {
    // Description : Looking for warp where it is closest spot from current position    
    for (int i = 0; i < 4; i++) {
        int hops = go(x, y, i);
        int nx = x + hops * dx[i];
        int ny = y + hops * dy[i];
        
        if (nx == x && ny == y) continue;   // case for search warp fail
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;  // out of range
        if (nx == 0 && ny == 0) continue;

        int next = min(visited[x][y][1] + 1, visited[x][y][0] + t + 1);
        if (visited[nx][ny][1] <= next) continue;

        visited[nx][ny][1] = next;
        q.push(make_pair(nx, ny));       
    }
}

void searchAdjacentSpot(int x, int y) {
    // Description : Search spot right next to current position
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (nx == 0 && ny == 0) continue;

        int next = min(visited[x][y][0] + 1, visited[x][y][1] + 1);
        if (visited[nx][ny][0] <= next) continue;

        visited[nx][ny][0] = next;
        q.push(make_pair(nx, ny));       
    }
}

void bfs(int a, int b) {

    init();
    visited[a][b][0] = 0;
    visited[a][b][1] = t; 
    q.push(make_pair(a, b));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
    
        q.pop();
        
        searchAdjacentSpot(x, y);
        searchWarp(x, y);
    }
}

int main() {

    scanf("%d %d %d %d", &N, &t, &r, &c);
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
        getchar();
    }
    bfs(0, 0);
    printf("%d\n", min(visited[r - 1][c - 1][0], visited[r - 1][c - 1][1]));
    return 0;
}