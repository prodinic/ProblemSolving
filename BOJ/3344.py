def printList(l) :

    for i in l :
        print(i)

def main() :
    n = int(input())
    ans = []
    if n % 6 == 2 or n % 6 == 3 :
        odd_number_list = []
        even_number_list = []
        for i in range(1, n + 1) :
            if (i % 2 == 0) :
                even_number_list.append(i)       
            else :
                odd_number_list.append(i)
        
        if n % 6 == 2 :
            odd_number_list[0], odd_number_list[1] = odd_number_list[1], odd_number_list[0]
            five = odd_number_list.pop(2)
            odd_number_list.append(five)
            ans = even_number_list + odd_number_list
        else :
            number_two = even_number_list.pop(0)
            even_number_list.append(number_two)
            number_one = odd_number_list.pop(0)
            number_three = odd_number_list.pop(0)
            odd_number_list.append(number_one)
            odd_number_list.append(number_three)
            ans = even_number_list + odd_number_list
    else :
        number_list = []
        for i in range(2, n + 1, 2) :
            number_list.append(i)
        for i in range(1, n + 1, 2) : 
            number_list.append(i)
        ans = number_list

    printList(ans)

if __name__ == "__main__" : 
    main()