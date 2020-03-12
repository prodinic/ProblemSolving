#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
#define INF (1ll<<40)
using namespace std;
struct Node {
   long long cost;
   vector<int> next;
   int near_infect_dist;
};
Node node[100001];
int n, m, k, s;
long long p, q;
vector<int> candidate;
long long dp[100001];
void dfs(int cur, int step) { // from 1
   if (step > s) return;
   Node cur_node = node[cur];
   for (auto i = cur_node.next.begin(); i != cur_node.next.end(); i++) {
      int next_idx = *i;
      if (node[next_idx].cost == INF ||
         node[next_idx].near_infect_dist <= step) continue;

      node[next_idx].near_infect_dist = step;
      node[next_idx].cost = q   ;
      dfs(next_idx, step + 1);
   }
   return;
}
int main() {
   scanf("%d %d %d %d", &n, &m, &k, &s);
   scanf("%lld %lld", &p, &q);
   for (int i = 1; i <= n; i++) {
      node[i].cost = p;
      node[i].near_infect_dist = 987654321;
      dp[i] = 0;
   }
   for (int i = 0; i < k; i++) {
      int invaded;
      scanf("%d", &invaded);
      node[invaded].cost = INF;
      candidate.push_back(invaded);
   }
   for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      node[a].next.push_back(b);
      node[b].next.push_back(a);
   }

   // Cost Aggregation
   for (int i = 0; i < candidate.size(); i++) {
      int cur = candidate[i];
      dfs(cur, 1);
   }

   memset(dp, -1, sizeof(long long) * 100001);
   // Min Cost Calculation
   priority_queue<pair<long long, int>> pq;
   pq.push({ 0ll, 1 });
   while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      long long cost = -cur.first;
      int idx = cur.second;

      if (dp[idx] >= 0) continue;
      dp[idx] = cost;

      // Success check
      if (idx == n) break;

      for (auto i = node[idx].next.begin(); i < node[idx].next.end(); i++) {
         int next = *i;
         if (dp[next] >= 0 || node[next].cost==INF) continue;
         pq.push({ -(cost + node[next].cost), *i});
      }
   }
   printf("%lld", dp[n]-node[n].cost);
}
