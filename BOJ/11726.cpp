#include <cstdio>
#define MAX_NUM 1001
int main() {

    int n, dp[MAX_NUM];

    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) dp[i] = 1;
        else dp[i] = ((dp[i - 1] % 10007) + (dp[i - 2] % 10007)) % 10007;        
    }
    printf("%d\n", dp[n]);
    return 0;
}