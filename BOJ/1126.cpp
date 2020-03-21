#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_NUM 51
#define MAX_HEIGHT 500001

using namespace std;

int N, dp[MAX_NUM][MAX_HEIGHT], p[MAX_NUM];
vector<int > v;
int answer;

void solve() {

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < MAX_HEIGHT; j++) {

            dp[i][j] = dp[i - 1][j];
            int new_block = p[i];
            if (j - new_block >= 0 && dp[i - 1][j - new_block] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - new_block] + new_block);
            }
            if (new_block - j >= 0 && dp[i - 1][new_block - j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][new_block - j] + j);
            }
            if (j + new_block < MAX_HEIGHT && dp[i - 1][j + new_block] != -1) { 
                dp[i][j] = max(dp[i][j], dp[i - 1][j + new_block]); 
            }
        }
    }
}

void init() {
    for (int i = 1; i < MAX_HEIGHT; i++) dp[0][i] = -1;
}

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        p[i] = a;
    }

    init();
    solve();
    
    if (dp[N][0] != 0) cout << dp[N][0] << "\n";
    else cout << -1 << "\n";

    return 0;
}