T = int(input())

for _ in range(0, T) :
    
    try : 
        a, b = map(int, input().split(','))
        print(a + b)

    except EOFError :
        break
