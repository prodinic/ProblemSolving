#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX_NUM 10001

using namespace std;

int dp[MAX_NUM][2];
int weights[MAX_NUM];
int n;
vector<vector<int> > connect(MAX_NUM);
vector<int> ans;

void printAll() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

int dfs(int prev, int from, bool is_vertex_chosen) {

    auto& total = dp[from][is_vertex_chosen];
    if (total != -1) return total;

    total = 0;

    for (int i = 0; i < connect[from].size(); i++) {
        int to = connect[from][i];
        
        if (prev == to) continue;

        if (is_vertex_chosen) {
            total += dfs(from, to, false);
        }
        else {
            int val1 = dfs(from, to, true) + weights[to];
            int val2 = dfs(from, to, false);

            total += max(val1, val2);
        }
    }
    return total;
}

void getAnswer(int prev, int from, int is_vertex_chosen) {

    if (is_vertex_chosen) {
        ans.push_back(from);
        for (int i = 0; i < connect[from].size(); i++) {
            int to = connect[from][i];

            if (prev == to) continue;

            getAnswer(from, to, 0);
        }
    }
    else {
        for (int i = 0; i < connect[from].size(); i++) {
            int to = connect[from][i];

            if (prev == to) continue;

            if (dp[to][0] < dp[to][1] + weights[to]) getAnswer(from, to, 1);
            else getAnswer(from, to, 0);
        }        
    }
}

int main() {

    int v1, v2;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i + 1]);
    }
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &v1, &v2);
        connect[v1].push_back(v2);
        connect[v2].push_back(v1);
    }

    int a = dfs(-1, 1, true) + weights[1];
    int b = dfs(-1, 1, false);
    // printf("===");
    // printAll();
    // printf("===");
    if (a > b) getAnswer(-1, 1, true);
    else getAnswer(-1, 1, false);

    sort(ans.begin(), ans.end());
    printf("%d\n", a > b ? a : b);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}