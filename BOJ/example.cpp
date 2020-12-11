#include <stdio.h>

int main() {

    int a;
    int& b = a;
    scanf("%d", &a);

    b = a;

    b = 5;

    printf("a : %d | b : %d\n", a, b);

    return 0;
}