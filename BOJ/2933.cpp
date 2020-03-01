#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std; 

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
char map[101][101];
int R, C, N, tmp;
vector<int> v;
vector<pair<int, int> > p;
bool visited[101][101] = {false, };
bool isBlocked;

void DFS(int a, int b) {

    visited[a][b] = true;
    p.push_back(make_pair(a, b));
    
    if (a == R - 1) {   // 바닥에 닿았을 경우 리턴합니다.
        isBlocked = true;
        return;
    }

    for (int j = 0; j < 4; j++) {
        
        int nx = a + dx[j];
        int ny = b + dy[j];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visited[nx][ny] == true) continue;
        if (map[nx][ny] == '.') continue;

        DFS(nx, ny);
    } 
}

void printAll() {
    // 입력 : 없음
    // 출력 : 없음
    // 설명 : 출력을 하는 함수입니다. 
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            cout << map[i][j];
        }
        cout << endl; 
    }

    return;
}

void down(vector<pair<int, int> > vp) {
    // 입력 : 클러스터의 위치를 저장하고 있는 리스트
    // 출력 : 없음
    // 설명 : 해당 클러스터의 위치를 확인 후 가능한한 아래로 움직입니다.

    int len = vp.size();
    bool loop = true;
    int hop = 0;

    for (int i = 0; i < len; i++) { //  맵 위에서 현재 클러스터를 지웁니다.
        int x = vp[i].first;
        int y = vp[i].second;
        map[x][y] = '.';
    }

    while(loop) {   // 클러스터가 얼마나 아래로 움직일 수 있는지 확인합니다.
        hop++;
        for (int i = 0; i < len; i++) {
            int x = vp[i].first + hop;
            int y = vp[i].second;

            if (x == R || map[x][y] == 'x') {
                loop = false;
                hop--;
                break;
            }
        }
    }

    for (int i = 0; i < len; i++) { // 클러스터를 hop수 만큼 아래로 이동합니다.
        vp[i].first += hop;
        int x = vp[i].first;
        int y = vp[i].second;
        map[x][y] = 'x';
    }
}

int main() {

    cin >> R >> C;
    char c;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            
            cin >> c;
            map[i][j] = c;

            if (c == 'x') {

                p.push_back(make_pair(i, j));   // 미네랄의 위치를 리스트로 저장합니다.
            }
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        
        cin >> tmp;
        v.push_back(tmp);
    }
    
    for (int i = 0; i < N; i++) {
        int x = R - v[i];
        int y = -1;
        // 왼쪽에서 오른쪽으로 탐색합니다.
        if (i % 2 == 0) {
            for(int j = 0; j < C; j++) {
                if (map[x][j] == 'x') {
                    y = j;  
                    break;
                }
            }
        }
        // 오른쪽에서 왼쪽으로 탐색합니다.
        else {
            for (int j = C - 1; j >= 0; j--) {
                if (map[x][j] == 'x') {
                    y = j;
                    break;
                }
            }
        }

        if (y == -1) continue;  // 미네랄이 없을 경우, 다음 사람의 순서로 넘깁니다.
        map[x][y] = '.';

        for (int j = 0; j < 4; j++) {   // 상하좌우 네 방향을 탐색합니다.
            
            p.clear();
            memset(visited, false, sizeof(visited));
            isBlocked = false;

            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;   // 맵의 범위를 벗어난 경우 다른 방향을 탐색합니다.
            if (map[nx][ny] == '.') continue;   // 미네랄이 없는 경우, 다른 방향을 탐색합니다.

            DFS(nx, ny);
            if (isBlocked) continue;    // 탐색 후, 아래로 내려가지 못할 경우 다른 방향을 탐색합니다. 

            down(p);    // 클러스터를 아래 방향으로 움직입니다.
        }
    }

    printAll(); // 모든 위치를 출력합니다.
    
    return 0;
}