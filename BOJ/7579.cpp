#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX_NUM 101

using namespace std;
int m[MAX_NUM], c[MAX_NUM];
int dp[MAX_NUM * MAX_NUM];
int N, M;

void solve() {

    int size = 0;
    for (int i = 0; i < N; i++) size += c[i];

    for (int i = 0; i < N; i++) {
        for (int j = size; j >= c[i]; j--) {
            
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
        }
    }

    for (int i = 0; i <= size; i++) {
        if (dp[i] >= M) {
            cout << i << "\n";
            return;
        }
    }
}
int main() {

    int a;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a;
        m[i] = a;
    }

    for (int i = 0; i < N; i++) {
        cin >> a;
        c[i] = a;
    }
    solve();

    return 0;
}