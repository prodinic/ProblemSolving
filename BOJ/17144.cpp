#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define p pair<int, int >

#define MAX_LEN 51

using namespace std;

int R, C, T;
vector<p > v, dirt;
int map[MAX_LEN][MAX_LEN];
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

void solve() {
    int answer = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == -1) continue;
            answer += map[i][j];
        }
    }
    cout << answer << endl;
    return; 
}

void simulation() {
    // 설명 : 공기청정기로 인한 1초 뒤의 먼지 분포를 저장합니다.

    // counter clock-wise circulation
    for (int i = v[0].first - 1; i > 0; i--) map[i][0] = map[i - 1][0];
    for (int i = 0; i < C - 1; i++) map[0][i] = map[0][i + 1];
    for (int i = 0; i < v[0].first; i++) map[i][C - 1] = map[i + 1][C - 1];
    for (int i = C - 1; i > 0; i--) {
        if (i == 1) {
            map[v[0].first][i] = 0;
            continue;
        }
        map[v[0].first][i] = map[v[0].first][i - 1];
    }

    // clock-wise circulation  
    for (int i = v[1].first + 1; i < R - 1; i++) map[i][0] = map[i + 1][0];
    for (int i = 0; i < C - 1; i++) map[R - 1][i] = map[R - 1][i + 1];
    for (int i = R - 1; i > v[1].first; i--) map[i][C - 1] = map[i - 1][C - 1];
    for (int i = C - 1; i > 0; i--) {
        if (i == 1) {
            map[v[1].first][i] = 0;
            continue;
        }
        map[v[1].first][i] = map[v[1].first][i - 1];
    } 
}

void countDirt() {
    dirt.clear(); 
    // update dirt position
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] > 0) {
                dirt.push_back(make_pair(i, j));
            }
        }
    }
}
void bfs() {
    // 설명 : 먼지의 확산 분포를 저장합니다.
    // 1. n/5 만큼 확산합니다
    // 2. 원래 위치에서 확산된 양만큼 제거
    // 3. dirt 위치 다시 갱신

    int tmp[MAX_LEN][MAX_LEN] = {0, };
    vector<p> vt;

    int len = dirt.size();
    for (int i = 0; i < len; i++) { 
        int x = dirt[i].first;
        int y = dirt[i].second;

        int cnt = 0;
        if (map[x][y] < 5) continue;
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;   // out of range
            if (map[nx][ny] == -1) continue; // avoid from air conditioner
            
            tmp[nx][ny] += (map[x][y] / 5);
            cnt++;
        }

        map[x][y] -= ((map[x][y] / 5) * cnt); 
    }

    dirt.clear(); 
    // update dirt position
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] += tmp[i][j];
        }
    }
}
int main() {

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            cin >> map[i][j];
            if (map[i][j] < 0) {
                v.push_back(make_pair(i, j));
            }
            else if (map[i][j] > 0) {
                dirt.push_back(make_pair(i, j));
            }
            else {
                continue;
            }
        }
    }

    while(T--) {
        bfs();
        simulation();
        countDirt();
    }
    solve();
    return 0;
}