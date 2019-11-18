#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX_N 18

using namespace std;

int main() {

    int n;
    bool map[MAX_N][MAX_N];
    bool chk[MAX_N][MAX_N] = {false, };
    queue<pair<pair<int, int>, int>> q;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int tmp;
            cin >> tmp;
            map[i][j] = tmp;

        }
    }

    q.push(make_pair(make_pair(0, 0), 0));
    chk[0][0] = true;
    
    int ans = 0;
    
    while(!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int type = q.front().second;

        q.pop();

        // cout<<ans<<endl;

        // horizontal
        if (type == 0) {
            
            if ((x == n - 1 && y + 2 == n - 1) || (x + 1 == n - 1 && y + 2 == n - 1)) {
                ans++;
                cout << "last pos : "<<x<<" "<<y<<" | type : "<<type<<endl;
                // continue;
            }

            bool isPossible = false;
            // move right            
            if (y + 2 < n && map[x][y + 2] == 0 && chk[x][y + 1] == false) {
                isPossible = true;
                q.push(make_pair(make_pair(x, y + 1), 0));
            }
            // move diagonal
            if (y + 2 < n && x + 1 < n && map[x][y + 2] == 0 && map[x + 1][y + 2] == 0 && map[x + 1][y + 1] == 0 && chk[x][y + 1] == false) {
                isPossible = true;
                q.push(make_pair(make_pair(x, y + 1), 2));
            }
            
            if (isPossible) chk[x][y + 1] = true;
            
        }
        // vertical
        else if (type == 1) {

            if ((x + 2 == n - 1 && y == n - 1) || (x + 2 == n - 1 && y + 1 == n - 1)) {
                ans++;
                cout << "last pos : "<<x<<" "<<y<<" | type : "<<type<<endl;
            }

            bool isPossible = false;
            // move down            
            if (x + 2 < n && map[x + 2][y] == 0 && chk[x + 1][y] == false) {
                isPossible = true;
                q.push(make_pair(make_pair(x + 1, y), 1));
            }

            // move diagonal
            if (y + 2 < n && x + 1 < n && map[x + 2][y] == 0 && map[x + 2][y + 1] == 0 && map[x + 1][y + 1] == 0 && chk[x + 1][y] == false) {
                isPossible = true;
                q.push(make_pair(make_pair(x, y + 1), 2));
            }

            if (isPossible) chk[x + 1][y] = true;
        }
        // diagonal
        else {

            if ((x + 2 == n - 1 && y + 2 == n - 1) || (x + 2 == n - 1 && y + 1 == n - 1) || (x + 1 == n - 1 && y + 2 == n - 1)) {
                ans++;
                cout << "last pos : "<<x<<" "<<y<<" | type : "<<type<<endl;
            }

            bool isPossible = false;
            if (y + 2 < n && map[x + 1][y + 2] == 0 && chk[x + 1][y + 1] == false) {
                isPossible = true;

                cout <<"x : "<<x<<" | y :"<<y<<" | type : 0"<<endl;
                q.push(make_pair(make_pair(x + 1, y + 1), 0));
            }
            if (x + 2 < n && map[x + 2][y + 1] == 0 && chk[x + 1][y + 1] == false) {
                isPossible = true;
                cout <<"x : "<<x<<" | y :"<<y<<" | type : 1"<<endl;

                q.push(make_pair(make_pair(x + 1, y + 1), 1));
            }
            if (y + 2 < n && x + 2 < n && map[x + 2][y + 2] == 0 && map[x + 2][y + 1] == 0 && map[x + 1][y + 2] == 0 && chk[x + 1][y + 1] == false) {
                isPossible = true;
                cout <<"x : "<<x<<" | y :"<<y<<" | type : 2"<<endl;

                q.push(make_pair(make_pair(x + 1, y + 1), 2));
            }
            
            if (isPossible) chk[x + 1][y + 1] = true;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << chk[i][j] << " "; 
        }
        cout << endl;
    }
    cout << ans <<endl;

    return 0;
}