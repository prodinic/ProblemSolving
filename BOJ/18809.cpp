#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define p pair<int, int>
#define MAX_LEN 51

using namespace std;

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int map[MAX_LEN][MAX_LEN];
vector<p> yellows, reds, greens;
bool checked[11];
int visited[MAX_LEN][MAX_LEN];
int N, M, G, R;

void bfs() {
    int stage = 0;
    queue<p> q;
    // greens 
    for (int i = 0; i < greens.size(); i++) {
        visited[greens[i].first][greens[i].second] = 0;
        q.push(greens[i]);
    }

    while(!q.empty()) {
        p here = q.front();
        q.pop();

        for (int j = 0; j < 4; j++) {
            int nx = here.first + dx[j];
            int ny = here.second + dy[j];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] == 0) continue;
            if (visited[nx][ny] >= 0) continue;

            visited[nx][ny] = visited[here.first][here.second] + 1; 
            q.push(make_pair(nx, ny));
        }
    }
    // reds
    for (int i = 0; i < reds.size(); i++) q.push(reds[i]);
    
    
    while(!q.empty()) {

    }


}
void dfs(int count_reds, int count_greens) {

    if (count_reds + count_greens == R + G) {
        memset(visited, -1, sizeof(visited));
        bfs();
        return;
    }
    for (int i = 0; i < yellows.size(); i++) {

        if (checked[i]) continue;

        if (count_reds < R) {
            checked[i] = true;
            reds.push_back(yellows[i]);
            dfs(count_reds + 1, count_greens);
            checked[i] = false;
            reds.pop_back();
        }

        if (count_greens < G) {
            checked[i] = true;
            greens.push_back(yellows[i]);
            dfs(count_reds, count_greens + 1);
            checked[i] = false;  
            greens.pop_back();          
        } 
    }

}

void solve() {



}

int main() {
    
    scanf("%d %d %d %d", &N, &M, &G, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) yellows.push_back(make_pair(i, j));
        }
    }

    solve();

    return 0;
}