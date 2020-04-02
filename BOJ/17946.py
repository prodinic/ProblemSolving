def pizza(n) :
    return (pow(n, 2) + n) / 2 + 1

def give(n) :
    return ((pow(n, 2)) + n) / 2

def main() :
    a = int(input())
    for i in range(1, a + 1) :
        b = int(input())
        print(1)
        # print("%d" %(pizza(b) - give(b)))

main()