MAX_NUM = 1001
DIVISOR = 10007

x = int(input())

dp = [0 for i in range(MAX_NUM)]
for i in range(0, MAX_NUM) :
    if i == 0 :
        dp[i] = 1

    elif i == 1 :
        dp[i] = 1

    else :
        dp[i] = (dp[i - 1] % DIVISOR + dp[i - 2] % DIVISOR) % DIVISOR

print(dp[x])