from collections import deque

def main():
    N = int(input())
    dq = deque()
    print(type(dq))
    answer = 0

    for _ in range(N):
        a, *rest = map(int, input().split())

        if a == 1:  # add tasks
            dq.append(rest)            
        
        if len(dq) > 0:  # work
            dq[-1][1] -= 1
            if dq[-1][1] <= 0:
                answer += dq[-1][0]
                dq.pop()
                    
    print(answer)

if __name__ == "__main__":
    main()