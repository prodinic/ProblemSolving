#include <iostream>
#include <vector>
#include <string.h>
#define STICKER_SIZE 11
#define LAPTOP_SIZE 40
using namespace std;

const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int laptop[LAPTOP_SIZE][LAPTOP_SIZE];
int s[STICKER_SIZE][STICKER_SIZE];
int R, C;

void printSticker(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
}

void printAll(int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << laptop[i][j] << " ";
        }   
        cout << "\n";
    }
}

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void init() {

    memset(s, 0, sizeof(s));
}

void rotate() {

    int tmp[R][C];
    
    for (int i = 0; i < R; i++) {   // rotate and copy
        for (int j = 0; j < C; j++) {

            tmp[i][j] = s[(C - 1) - j][i];
        }
    }
    init(); // initiate array s
    
    for (int i = 0; i < R; i++) {   // paste
        for (int j = 0; j < C; j++) {

            s[i][j] = tmp[i][j];
        }
    }
}

bool isPossible(int r, int c, int N, int M) {

    for (int i = 0; i + r - 1 < N; i++) {
        for (int j = 0; j + c - 1 < M; j++) {
            
            bool flag = true;
            for (int k = 0; k < r; k++) {
                for (int l = 0; l < c; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (s[k][l] == 1 && laptop[x][y] == 1) {    // location is already stuck with sticker
                        flag = false;
                    }
                }
            }

            if (!flag) continue;    // continue if it cannot be stuck on laptop

            for (int k = 0; k < r; k++) {   // paste sticker onto laptop
                for (int l = 0; l < c; l++) {
                    int x = i + k;
                    int y = j + l;

                    if (laptop[x][y] != 1) laptop[x][y] = s[k][l];
                }
            }

            return true;
        }
    }

    return false;
}

void solve(int N, int M) {

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if(laptop[i][j] == 1) answer++;
        }
    }

    cout << answer << "\n";
}
int main() {

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {

        cin >> R >> C;

        // for sticker
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                
                cin >> s[j][k];
            }
        }
        // cout << "original" << "\n";
        // printSticker(R, C);
        for (int j = 0; j < 4; j++) {
            if (isPossible(R, C, N, M)) {
                break;
            }
            else {
                swap(&R, &C);
                rotate();
                // cout << "j : "<<j << "\n";
                // printSticker(R, C);
            }
        }

        // cout << "lap : "<<i<<"\n";
        // printAll(N, M);
    }

    solve(N, M);
    return 0;
}