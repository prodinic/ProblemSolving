#include <cstdio>
#define MAX_LEN 111


bool BinarySearch(int k, int len, int a[]) {

    int _left, _right = len, mid;

    while(_left <= _right) {
        mid = (_left + _right) / 2;

        if (a[mid] > k) _right = mid - 1;
        else if (a[mid] == k) return true;
        else _left = mid + 1;
    }

    return 0;
}

int main() {

    int arr[] = {1, 5, 9, 23, 44, 58, 97, 1233, 4321, 58586};
    int n;
    scanf("%d", &n);
    printf("%d", BinarySearch(n, 10, arr));
    return 0;
}