#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_LEN 52
#define info pair<int, pair<int, int > >

using namespace std; 

char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int expected[MAX_LEN][MAX_LEN] = {0, }; 
vector<info> loc;
int R, C;
info destination;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int answer = -1;

void printAll() {
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << expected[i][j]; 
        }
        cout << endl;
    }
    cout << endl;

}
void simulation() {
    // Input : 
    // Output :
    // Description :

    // find the location expected to be filled with water 
    priority_queue<info> pq;

    // init 
    for (int i = 0; i < loc.size(); i++) {
        int x = loc[i].second.first;
        int y = loc[i].second.second;
        int step = loc[i].first + 1;

        pq.push(make_pair(-step, make_pair(x, y)));
        expected[x][y] = step;
    }

    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int step = -pq.top().first;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;   // out of range
            if (expected[nx][ny]) continue;
            if (map[nx][ny] == 'D' || map[nx][ny] == 'X') continue;

            expected[nx][ny] = step + 1;
            pq.push(make_pair(-(step + 1), make_pair(nx, ny)));
        }
    }

}

void bfs(info start) {

    priority_queue<pair<int, pair<int, int > > > pq;
    visited[start.second.first][start.second.second] = true;
    pq.push(start);

    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int step = -pq.top().first;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;   // out of range
            if (map[nx][ny] == '*' || map[nx][ny] == 'X') continue; // water or stone
            if (visited[nx][ny]) continue;  // check it is visited or not
            if (map[nx][ny] == 'D') {
                answer = step + 1;
                return;
            }
            if (expected[nx][ny] != 0 && (expected[nx][ny] - 1 <= step + 1)) continue;

            // move
            visited[nx][ny] = true;
            pq.push(make_pair(-(step + 1), make_pair(nx, ny)));
        }
    }

}
int main() {

    cin >> R >> C;
    info start;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j]; 
            if (map[i][j] == 'S') {
                start.second.first = i; 
                start.second.second = j;
                start.first = 0;
            }
            if (map[i][j] == 'D') {
                destination.second.first = i;
                destination.second.second = j;
                destination.first = -1;
            }
            if (map[i][j] == '*') {
                loc.push_back(make_pair(0, make_pair(i, j)));
            }
        }
    }

    simulation();
    // printAll();
    // cout << "-----"<< endl;
    bfs(start);
    if (answer == -1) cout << "KAKTUS" << endl;
    else cout << answer << endl;

    return 0;
}