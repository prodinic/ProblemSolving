#include <stdio.h>
#define MAX_NUM 1000000000
#define ll long long int

void solve(ll remainder, ll divisor) {

    

}

int main() {

    ll counts[10];
    ll N, divisor = MAX_NUM;
    scanf("%lld", &N);

    while(N / divisor == 0) {
        divisor /= 10;
    }

    solve(N, divisor);
    return 0;
}