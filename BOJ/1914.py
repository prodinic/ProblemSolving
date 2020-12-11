def hanoi(n, start, here, there) :

    if n == 1 :
        print("%d %d" % (start, there))
    else :
        hanoi(n - 1, start, there, here)
        print(start, there, sep=" ")
        hanoi(n - 1, here, start, there)

def main() :

    a = int(input())
    print(pow(2, a) - 1)
    if a <= 20 :
        hanoi(a, 1, 2, 3)

if __name__ == "__main__" :

    main()