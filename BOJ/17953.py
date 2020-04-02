import sys
import math
N, M = map(int, input().split())
dp = [[0 for i in range(N)] for j in range(M)]

for i in range(M):
    I = sys.stdin.readline
    dp[i] = [int(x) for x  in I().split()]

for i in range(N):
    max_num = -1
    if i == 0:
        continue
    for j in range(M):
        prior_max = -1
        for k in range(M):
            if k == j:
                prior_max = max(prior_max, dp[k][i - 1] + math.floor(dp[j][i] / 2))
            else:
                prior_max = max(prior_max, dp[k][i - 1] + dp[j][i])
        # print(prior_max)
        dp[j][i] = prior_max

max_num = -1
for i in range(M):
    max_num = max(max_num, dp[i][N - 1])

print (max_num)