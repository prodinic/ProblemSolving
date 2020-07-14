#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX_ROWS 10001
#define MAX_COLS 501

using namespace std;

int ans = 0;
int R, C;
int dx[] = {-1, 0, 1}, dy[] = {1, 1, 1};
char map[MAX_ROWS][MAX_COLS];
bool visited[MAX_ROWS][MAX_COLS];
bool isViableRoute = false;

void printMap() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
void printAll() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

void go(int x, int y) {

    if (y == C - 1) {
        isViableRoute = true;
        ans++;
        // printf("%d\n", ans);
        // printAll();
        return;
    }

    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[nx][ny] || map[nx][ny] == 'x') continue;
        if (isViableRoute) return;  // terminate program as soon as it gets to destination
        
        visited[nx][ny] = true;
        go(nx, ny);
    }
}

int main() {

    char c;
    scanf("%d %d", &R, &C);
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;
            map[i][j] = c;
            // scanf("%c", &map[i][j]);
        }
        // getchar();
    }
    // printf("---\n");
    // printMap();
    // printf("---\n");

    for (int from = 0; from < R; from++) {
        isViableRoute = false;
        visited[from][0] = true;
        go(from, 0);
    }

    printf("%d\n", ans);
    return 0;
}