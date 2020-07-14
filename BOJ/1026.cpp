#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX_LEN 51

using namespace std;

vector<int> A, B;
int S = 0, N;


bool compare(int a, int b) {
    if (a > b) return true;
    else return false;
}

int main() {

    int tmp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        B.push_back(tmp);
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), compare);

    for (int i = 0; i < N; i++) {
        S += A[i] * B[i];
    }

    printf("%d\n", S);
    return 0;
}