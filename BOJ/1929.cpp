#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#define MAX_NUM 1000001

using namespace std;

int N, M;
int arr[MAX_NUM];
vector<int> primes;

void printAll() {
    for (int i = 0; i < primes.size(); i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}
void init () {
    for (int i = 0; i < MAX_NUM; i++) {
        arr[i] = i;
    }
}
void getPrimeNumbers(int tmp) {
    vector<int> v(MAX_NUM);
    for (int i = 0; i <= tmp; i++) {
        v[i] = i;
    }
    for (int i = 2; i <= tmp; i++) {
        for (int j = i; j <= tmp; j += i) {
            if (v[j] == i || v[j] == 0) continue;
            if (v[i] % i == 0) v[j] = 0; 
        }
    }
    for (int i = 2; i <= tmp; i++) {
        if (v[i] != 0) primes.push_back(i);
    }
}
void solve(float tmp) {
    getPrimeNumbers((int)tmp);
    // printAll();
    for (auto& prime : primes) {
        for (int i = prime; i <= M; i += prime) {
            if (arr[i] == prime || arr[i] == 0) continue;
            if (arr[i] % prime == 0) arr[i] = 0;
        }
    }
    for (int i = N; i <= M; i++) {
        if (i != 1 && arr[i] != 0) printf("%d\n", arr[i]);
    }
}

int main() {
    init();
	//에라토스테네스의 체 
    float tmp;
	scanf("%d %d", &N, &M);
	tmp = sqrt(M);
    // printf("tmp : %f\n", tmp);
    solve(tmp);
	
	return 0;
}