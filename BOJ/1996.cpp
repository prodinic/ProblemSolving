#include <iostream>
#include <vector>
#define p pair<int, int >
#define MAX_LEN 1001

using namespace std;

int n, dx[] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
bool visited[MAX_LEN][MAX_LEN];
char map[MAX_LEN][MAX_LEN];

void printAll() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

int main() {

    vector<p > v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if ('1' <= map[i][j] && map[i][j] <= '9') {

                visited[i][j] = true;
                v.push_back(make_pair(i, j));
            }
            if (map[i][j]== '.') map[i][j] = '0';
        }
    }

    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;
        int from = map[x][y] - '0';
        // cout << "map[x][y] : " << map[x][y] << " | from : " << from << "\n";

        map[x][y] = '*';

        for (int j = 0; j < 8; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] == 'M' || map[nx][ny] == '*') continue;
            
            int to = map[nx][ny] - '0';
   
            if (to + from > 9) {
                // cout << "x : "<< x << " | y : "<< y << " | map[x][y] : "<< map[x][y] << " | from + to : "<<from + to<<"\n";
                map[nx][ny] = 'M';
            }
            else {
                // cout << "x : "<< x << " | y : " << y << " | nx : " << nx << " | ny : "<< ny << "\n"; 
                map[nx][ny] += from;
            }
        }
    }

    printAll();
    return 0;
}