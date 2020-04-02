def main() :

    s = input()
    n = int(input())

    i = 0
    for t in input().split() :
        if t == "char" :
            print(int(s[i:i+2], 16), end=" ")
            i += 2
        elif t == "int" :
            print(int(s[i:i+8], 16), end=" ")
            i += 8
        else : 
            print(int(s[i:i+16], 16), end=" ")
            i += 16


if __name__ == "__main__" :
    main()