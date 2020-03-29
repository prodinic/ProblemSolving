N, T = map(int, input().split())

answer = 0
flag = True
for _ in range(1, T + 1) :
    if flag == True :
        answer += 1

        if answer == 2 * N :
            flag = False
            
    else :
        answer -= 1

        if answer == 1 :
            flag = True


print(answer)