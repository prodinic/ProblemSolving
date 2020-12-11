#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define MAX_NUM 1000001

using namespace std;

int dp[MAX_NUM][2];
bool visited[MAX_NUM] = {false, };
vector<int> edges[MAX_NUM];

void dfs(int from) {

    // int& ans = dp[from][is_early_adopter];
    // if (ans != -1) return ans;
    
    // if (is_early_adopter) ans = 1;
    // else ans = 0;

    visited[from] = true;
    dp[from][1] = 1;

    for (int i = 0; i < edges[from].size(); i++) {
        // printf("size : %d\n", edges[from].size());
        int to = edges[from][i]; 
        if (visited[to]) continue;
        dfs(to);
        
        dp[from][0] += dp[to][1];
        dp[from][1] += min(dp[to][0], dp[to][1]);

        // if (!is_early_adopter) ans += dfs(to, !is_early_adopter);
        // else {
        //     ans += min(dfs(to, !is_early_adopter), dfs(to, is_early_adopter));
        // }
    }

    visited[from] = false;
    // return ans;
}

int main() {

    int N, a, b;

    scanf("%d", &N);

    memset(dp, 0, sizeof(dp));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a, &b);
        // if (!visited[a]) visited[a] = true;
        // if (!visited[b]) visited[b] = true;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);
    printf("%d\n", min(dp[1][0], dp[1][1]));
    return 0;
}