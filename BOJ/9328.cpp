#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>

#define MAX_LEN 101

using namespace std;

int h, w, N;
char map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
bool keys[26];
vector<pair<int, int> > enterance; 

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int answer = 0;
bool isKeyFound = false;

void BFS(int a, int b) {

    queue<pair<int, int > > q;

    q.push(make_pair(a, b));
    visited[a][b] = true;

    while(!q.empty()) {

        int x = q.front().first; 
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visited[nx][ny] == true) continue;
            if (map[nx][ny] == '*') continue;

            if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
                keys[map[nx][ny] - 'a'] = true;
                map[nx][ny] = '.';
                isKeyFound = true;
                return;
            }
            if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
                if (keys[map[nx][ny] - 'A'] == true) {
                    map[nx][ny] = '.';
                }
                else {
                    continue;
                }
            }
            if (map[nx][ny] == '$') {
                answer++;
                map[nx][ny] = '.';
            }

            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }


}
int main() {

    string s;

    cin >> N; 

    for (int i = 0; i < N; i++) {

        cin >> h >> w;
        memset(keys, false, sizeof(keys));
        enterance.clear();
        answer = 0;

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {

                cin >> map[j][k];
                if ((k == 0 || k == w - 1 || j == 0 || j == h - 1) && map[j][k] != '*') {
                    // cout << "j : " << j << " | k = " << k << " | value : " << map[j][k] << endl; 
                    enterance.push_back(make_pair(j, k));
                } 
            }
        }

        cin >> s;

        if (s != "0") {
           
            for (int j = 0; j < s.length(); j++) {
                int key = s[j] - 'a';
                keys[key] = true;
            }
        }

        while(1) {
            int cnt = 0;
            for (int j = 0; j < enterance.size(); j++) {
                int x = enterance[j].first;
                int y = enterance[j].second;
                
                isKeyFound = false;
                memset(visited, false, sizeof(visited));
                
                if ('a' <= map[x][y] && map[x][y] <= 'z') {
                    keys[map[x][y] - 'a'] = true;
                    map[x][y] = '.';
                    break;
                }
                else if ('A' <= map[x][y] && map[x][y] <= 'Z') {
                    if (keys[map[x][y] - 'A'] == true) {
                        map[x][y] = '.';
                        // cout << "error" << endl;
                        
                    }
                    else {
                        cnt++;
                        continue;
                    }
                }
                else if (map[x][y] == '$') {
                    answer++;
                    map[x][y] = '.';
                }

                BFS(x, y);
                if (isKeyFound == false) cnt++; 
            }
            if (cnt == enterance.size()) break;
        }

        cout << answer << endl;
    }


    return 0;
}