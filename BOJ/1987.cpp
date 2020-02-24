#include <iostream>
#include <vector>

using namespace std;

int map[22][22];
int answer = 0;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int R, C;  

// call by value
void dfs (int x, int y, bool alphabet[], int ret) {

    // cout << "---start dfs---";
    if (answer < ret) answer = ret;

    for (int i = 0; i < 4; i++) {
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= R) continue;
        if (ny < 0 || ny >= C) continue;
        
        int cur = map[nx][ny] - 'A';

        if (alphabet[cur]) continue;

        alphabet[cur] = true;
        dfs(nx, ny, alphabet, ret + 1);
        alphabet[cur] = false;
    }
}
int main() {

    bool alphabet[26] = {false, };
    char ch;

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            cin >> ch;
            map[i][j] = ch;
        }
    }
    
    alphabet[map[0][0] - 'A'] = true;
    dfs(0, 0, alphabet, 1);

    cout << answer << endl;

    return 0;
}