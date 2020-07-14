#include <stdio.h>
#define MAX_NUM 100000
#define LOWEST_VALUE -1000000001

int n;
int arr[MAX_NUM];
int dp[MAX_NUM];

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

void printAll() {
    for (int i = 0; i < n; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
}

int getMaximumValue() {
    int answer = LOWEST_VALUE;
    for (int i = 0; i < n; i++) {
        if (answer < dp[i]) answer = dp[i];
        else continue;
    }
    return answer;
}
int main() {

    scanf("%d" , &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) dp[i] = arr[i];
        else dp[i] = max(arr[i], dp[i - 1] + arr[i]);
    }
    // printAll();
    printf("%d\n", getMaximumValue());
}
