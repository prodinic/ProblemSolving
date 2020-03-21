#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_NUM 20002

using namespace std; 

int T, N, W;

int map[MAX_NUM];
int dp[MAX_NUM];

int solve() {



}

int main() {

    cin >> T;

    while (T--) {
        cin >> N >> W;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i * N + j];
            }
        }
    }





    return 0;
}