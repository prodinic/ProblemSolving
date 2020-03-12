#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_LEN 1001
#define pp pair<int, pair<int, int > >

using namespace std;

int R, C;
char map[MAX_LEN][MAX_LEN];
int fires[MAX_LEN][MAX_LEN] = {0, };
bool visited[MAX_LEN][MAX_LEN];
pair<int, int> jihoon;
vector<pair<int, int > > fire;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int answer = -1;

void printAll() {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << fires[i][j];
        }
        cout << endl;
    }
}

void simulation() {
    // Description : check the location of fire

    priority_queue<pp> pq;

    for (int i = 0; i < fire.size(); i++) {
        fires[fire[i].first][fire[i].second] = 1;
        pq.push(make_pair(-1, make_pair(fire[i].first, fire[i].second)));        
    }

    while(!pq.empty()) {

        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int step = -pq.top().first;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (map[nx][ny] == '#') continue;
            if (fires[nx][ny] > 0) continue;    // already visited

            fires[nx][ny] = step + 1;
            pq.push(make_pair(-(step + 1), make_pair(nx, ny)));
        }
    }
}

void bfs() {

    priority_queue<pp> pq;
    visited[jihoon.first][jihoon.second] = true;
    pq.push(make_pair(0, make_pair(jihoon.first, jihoon.second)));
    
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int step = -pq.top().first;
        pq.pop();

        if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
            answer = step + 1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;   // out of range
            if (visited[nx][ny]) continue;   // already visited 
            if (map[nx][ny] == '#' || map[nx][ny] == 'F') continue; // blocked with the wall and fire
            if (fires[nx][ny] != 0 && (step + 1 >= (fires[nx][ny] - 1))) continue;    // on the fire spot

            visited[nx][ny] = true;
            pq.push(make_pair(-(step + 1), make_pair(nx, ny)));            
        }
    }
}

int main() {

    jihoon.first = -1, jihoon.second = -1;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            
            cin >> map[i][j];
            if (map[i][j] == 'J') {
                jihoon.first = i;
                jihoon.second = j;
            }
            if (map[i][j] == 'F') {
                fire.push_back(make_pair(i, j));
            }   
        }
    }

    if (fire.size()) simulation();
    if (jihoon.first != -1 || jihoon.second != -1) bfs();
    if (answer == -1) cout << "IMPOSSIBLE" << endl;
    else cout << answer << endl;

    return 0;
}
