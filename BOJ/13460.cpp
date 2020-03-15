#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pp pair<pair<int, int>, pair<int, int > >
#define MAX_LEN 11

using namespace std; 

char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int N, M;
bool flag = false, flag2 = false;
pair<int, int > red, blue, out;
int answer = 0;

bool isRedAhead(int dir) {
    // Input : direction
    // Output : boolean value
    // Description : if red ball is ahead of blue ball, return true. Otherwise, return false

    // left
    if (dir == 0) {
        if (red.second > blue.second) return false;
        else return true;
    }
    // upward
    else if (dir == 1) {
        if (red.first > blue.first) return false;
        else return true;
    } 
    // right
    else if (dir == 2) {
        if (red.second > blue.second) return true;
        else return false;
    }
    // downward
    else {
        if (red.first > blue.first) return true;
        else return false;
    }
}

int move(int x, int y, int dir) {

    int cnt = 0;
    while(1) {
        // move the ball until it gets to wall or ball which has diffent color
        if (map[x + dx[dir]][y + dy[dir]] == '#' || map[x + dx[dir]][y + dy[dir]] == 'O') {
            if (map[x + dx[dir]][y + dy[dir]] == 'O') flag = true;    // check it gets to destination
            break;
        }
        else {
            x += dx[dir];
            y += dy[dir];

            cnt++;
        }
    }
    
    return cnt;
}

void printAll() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void bfs(pp s) {

    priority_queue<pair<int, pp> > pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()) {
        int rx = pq.top().second.first.first;    // check current position
        int ry = pq.top().second.first.second;
        int bx = pq.top().second.second.first;
        int by = pq.top().second.second.second;
        int step = -pq.top().first;
        red.first = rx, red.second = ry, blue.first = bx, blue.second = by;
        pq.pop();

        if (step > 9) {
            cout << -1 << endl;
            return;
        }
        // cout << "step : "<< step << " | bx : "<< bx << " | by : "<< by << " | rx : "<<rx << " | ry : "<<ry << endl;

        for (int i = 0; i < 4; i++) {   // check next step
            int cnt, nrx, nry, nbx, nby;
            flag = false, flag2 = false;

            if (isRedAhead(i)) { // move red first until it gets to wall
                cnt = move(rx, ry, i); // move red ball
                nrx = rx + cnt * dx[i];
                nry = ry + cnt * dy[i];
                flag2 = flag;

                flag = false;
                cnt = move(bx, by, i); // move blue ball
                nbx = bx + cnt * dx[i];
                nby = by + cnt * dy[i];     
                if (flag2 == true && flag == false) {   // return if red ball gets to the hole and blue ball doesn't
                    cout << step + 1 << endl;
                    return;
                }    
                if (flag == true) continue;   
                if ((nrx == nbx) && (nry == nby)) {
                    nbx -= dx[i];
                    nby -= dy[i];                       
                }
            }
            else {  // move blue first
                cnt = move(bx, by, i); // move blue ball
                nbx = bx + cnt * dx[i];
                nby = by + cnt * dy[i];
                if (flag) continue; // if blue ball gets to the hole, then continue

                flag = false;
                cnt = move(rx, ry, i); // move red ball
                nrx = rx + cnt * dx[i];
                nry = ry + cnt * dy[i];
                
                if (flag) {
                    cout << step + 1 << endl;
                    return;                    
                }  
                if ((nrx == nbx) && (nry == nby)) {
                    // if (step == 7) {
                    //     cout << "step : "<< step << " | dir : "<< i << " | bx : "<< bx << " | by : "<< by << " | rx : "<<rx << " | ry : "<<ry << endl;
                    //     cout << "kkk" << endl;
                    // }
                    nrx -= dx[i];
                    nry -= dy[i];                       
                }        
            }

            if (nbx < 0 || nbx >= N || nby < 0 || nby >= M) continue;   // out of range
            if (nrx < 0 || nrx >= N || nry < 0 || nry >= M) continue;   // out of range
            if (rx == nrx && ry == nry && bx == nbx && by == nby) continue; // if both of balls have same position, then continue
            // printAll();
            // cout << endl;
            pq.push(make_pair(-(step + 1), make_pair(make_pair(nrx, nry), make_pair(nbx, nby))));
            // cout << "nrx : "<<nrx<< " | nry : "<<nry << " | nbx : "<<nbx << " | nby : "<<nby << " | dir : "<< i << endl;
        }
    }

    cout << -1 << endl;
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'R') {
                red.first = i;
                red.second = j;
                map[i][j] = '.';
            }
            if (map[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
                map[i][j] = '.';
            }
            if (map[i][j] == 'O') {
                out.first = i;
                out.second = j; 
            }
        }
    }
    // cout << "test" << endl;
    pp s;
    s.first.first = red.first, s.first.second = red.second, s.second.first = blue.first, s.second.second = blue.second;

    bfs(s);

    return 0;
}

// Q1. what if the position where red ball already visited there is visited by blue ball next? 