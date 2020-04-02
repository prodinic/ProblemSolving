import math

a, b = map(int, input().split())

c = math.sqrt(pow(a, 2) - b) 

if c > 0 :
    print("%d %d" %(-a - c, -a + c))

elif c == 0 :
    if a == 0 : 
        print("%d" %(math.sqrt(b)))
    else :
        print("%d" %((-b) / a))

else :
    print(-1)