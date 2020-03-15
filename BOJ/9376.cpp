#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define MAX_LEN 102
#define pp pair<int, pair<int, int > > 
#define p pair<int, int >
#define INF 987654321
using namespace std;

int t, h, w;
char map[MAX_LEN][MAX_LEN];
int record[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0}; 

void bfs(int a, int b) {

    priority_queue<pp> pq; 
    visited[a][b] = true;
    pq.push(make_pair(0, make_pair(a, b)));

    while(!pq.empty()) {
        int door = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        record[x][y] += door;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue; // out of range
            if (map[nx][ny] == '*') continue; // against the wall
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == '#') {
                // cout << "nx : "<<nx << " | ny : "<< ny << endl;
                pq.push(make_pair(-(door + 1), make_pair(nx, ny)));        
            }
            else {
                pq.push(make_pair(-(door), make_pair(nx, ny)));
            }

            visited[nx][ny] = true;
        }
        // cout << "test" << endl;
    }
}
void init() {

    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            map[i][j] = '.';
        }
    }
}

void printAll() {
    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            
            cout << record[i][j] << " ";
        }
        cout << endl;
    }
}

void getAnswer() {
    
    int answer = INF;

    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            
            if (map[i][j] == '#') {
                record[i][j] -= 2;
            }
        }
    }  
    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            
            if (map[i][j] != '*') {
                if (answer > record[i][j]) {
                    answer = record[i][j];
                }
            }
        }
    }  
    cout << answer << endl;  
}
int main() {

    char c;
    cin >> t;
    vector<pair<int, int > > v;
    while(t--) {
     
        cin >> h >> w;
        // input
        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                record[i][j] = 0;
                if (i == 0 || i == h + 1 || j == 0 || j == w + 1) {
                    map[i][j] = '.';
                }
                else {
                    cin >> c;
                    map[i][j] = c;
                    if (c == '$') v.push_back(make_pair(i, j));
                }
            }
        }

        bfs(0, 0);  // from (0, 0)
        memset(visited, false, sizeof(visited));
        // printAll();
        // cout << endl;
        bfs(v[0].first, v[0].second);  // from $1
        memset(visited, false, sizeof(visited));
        // printAll();
        // cout << endl;
        bfs(v[1].first, v[1].second);  // from $2
        memset(visited, false, sizeof(visited));
        // printAll();
        // cout << endl;
        getAnswer();
        v.clear();
    }

    return 0;
}