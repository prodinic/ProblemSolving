MAX_NUM = 1001
dp = list()

def solve() :

    for i in range(0, N) :
        if i == 0 : 
            continue
        else :   
            for j in range(0, 3) :
                dp[i][j] += min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3])

def main() : 
 
    for i in range(0, N) :
        try : 
            a, b, c = map(int, input().split())  
            dp[i][0] = a
            dp[i][1] = b
            dp[i][2] = c
            
        except EOFError:
            break 
    solve()
    print(min(dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]))   

if __name__ == "__main__" :
    
    N = int(input())
    dp = [[0 for i in range(0, 3)] for j in range(0, N + 1)]
    main()