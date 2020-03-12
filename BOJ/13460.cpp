#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_LEN 11

using namespace std; 

struct info {
    int rx, ry;
    int bx, by;
};
char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int N, M;
pair<int, int > red, blue, out;
int answer = 0;

int move(int x, int y, int dir) {

    int ret = 1;

    while(1) {

        int nx = x + dx[dir] * (ret - 1);
        int ny = y + dy[dir] * (ret - 1);

        if (map[nx][ny] == '#') continue;
        if (visited[nx][ny]) continue;

        ret++;
    }

    return ret;
}

void bfs(info s) {

    priority_queue<pair<int, info> > pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        int rx = pq.top().second.rx;
        int ry = pq.top().second.ry;
        int bx = pq.top().second.bx;
        int by = pq.top().second.by;
        int step = -pq.top().first;

        for (int i = 0; i < 4; i++) {
            int nrx = rx + dx[i];
            int nry = ry + dy[i];
            int nbx = bx + dx[i];
            int nby = by + dy[i];

            if (nrx < 0 || nrx >= N || nry < 0 || nry >= M) continue;
            if (nbx < 0 || nbx >= N || nby < 0 || nby >= M) continue;
            if (map[nrx][nry] == '#' && map[nbx][nby] == '#') continue; // against the wall
            if (nrx == nbx) {   // if it is on the same horizontal line
                if (i == 0 || i == 2) {
                    if (nry < nby) {    // red ball is prior to blue ball
                        nry = ry + dy[i] * move(nrx, nry, i);
                    }
                    else {

                    }                    
                }
            }
            else if (nry == nby) {   // if it is on the same vertical line
                if (i == 1 || i == 3) {
                    if (nrx < nbx) {

                    }
                    else {

                    }
                }
            }
            else {  // it is not located in neither a nor b

            }
        }
    }

}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                red.first = i;
                red.second = j;
            }
            if (map[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
            }
            if (map[i][j] == 'O') {
                out.first = i;
                out.second = j; 
            }
        }
    }

    info s;
    s.bx = blue.first, s.by = blue.second, s.rx = red.first, s.ry = red.second;

    bfs(s);

    return 0;
}