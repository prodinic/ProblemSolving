#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <limits.h>
#define MAX_LEN 22

using namespace std;

int map[MAX_LEN][MAX_LEN];
int arr[MAX_LEN][MAX_LEN];
int N;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
long long int answer = INT_MAX;
vector<int> v(6, 0);

void one(int x, int y, int d1, int d2) {

 	for(int r = 1; r < x + d1; r++) {
        for(int c = 1; c <= y; c++) {
            map[r][c]=1;
        }
    }
}

void two(int x, int y, int d1, int d2) {

	for(int r=1; r<=x+d2; r++) {
        for(int c=y+1; c<=N; c++) {
            map[r][c]=2;
        }
    }
}

void three(int x, int y, int d1, int d2) {

    for(int r=x+d1; r<=N; r++) {
        for(int c= 1; c<y-d1+d2; c++) {
            map[r][c]=3;
        }
    }
}

void four(int x, int y, int d1, int d2) {

    for(int r=x+d2+1; r<=N; r++) {
        for(int c=y-d1+d2; c<=N; c++) {
            map[r][c]=4;
        }
    }
}

void five(int x, int y, int d1, int d2) {

    for (int i = 0; i <= d1; i++) {
        map[x + i][y - i] = 5;
    }
    for (int i = 0; i <= d2; i++) {
        map[x + i][y + i] = 5;
    }
    for (int i = 0; i <= d2; i++) {
        map[x + d1 + i][y - d1 + i] = 5; 
    }
    for (int i = 0; i <= d1; i++) {
        map[x + d2 + i][y + d2 - i] = 5; 
    }

    for (int i = 0; i < d1; i++) {
        int a = x + i + 1;
        int b = y - i;

        queue<pair<int, int > > q;
        q.push(make_pair(a, b));

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            map[r][c] = 5;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = r + dx[j];
                int ny = c + dy[j];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (map[nx][ny] == 5) continue;

                // map[nx][ny] = 5;
                q.push(make_pair(nx, ny)); 
            }
        }
    }
    for (int i = 0; i < d2; i++) {
        int a = x + i + 1;
        int b = y + i;

        queue<pair<int, int > > q;
        q.push(make_pair(a, b));

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            map[r][c] = 5;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = r + dx[j];
                int ny = c + dy[j];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (map[nx][ny] == 5) continue;

                // map[nx][ny] = 5;
                q.push(make_pair(nx, ny)); 
            }
        }
    }
}
void printAll() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            cin >> arr[i][j];
        }
    }

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d1 <= N; d1++) {
                    
                    if(x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N) {
                        one(x, y, d1, d2); 
                        two(x, y, d1, d2); 
                        three(x, y, d1, d2); 
                        four(x, y, d1, d2); 
                        five(x, y, d1, d2);

                        for (int a = 1; a <= 5; a++) {
                            v[a] = 0;
                        }

                        for (int a = 1; a <= N; a++) {
                            for (int b = 1; b <= N; b++) {

                                v[map[a][b]] += arr[a][b];
                            }
                        }

                        long long int max_num = INT_MIN;
                        long long int min_num = INT_MAX;

                        for (int a = 1; a <= 5; a++) {
                            if (max_num < v[a]) max_num = v[a];
                            if (min_num > v[a]) min_num = v[a];
                        }

                        if (answer > max_num - min_num) {
                            
                            answer = max_num - min_num;
                        }
                        memset(map, 0, sizeof(map));
                        // v.clear();
                    }
                }
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}