import sys

H, x = map(int, input().split())
answer = 0
dp = [0 for i in range(1000001)]

for i in range(1, 1000001):
    if i == 1:
        dp[i] = x
    else:
        dp[i] = (dp[i - 1] * x) % 1000000007

# dp = [pow(x, i) % 1000000007 for i in range(1, 1000001)]
  
for i in range(1, H + 1):
    a = int(sys.stdin.readline())

    answer = (answer % 1000000007 + (a * dp[i]) % 1000000007) % 1000000007

print(answer)
