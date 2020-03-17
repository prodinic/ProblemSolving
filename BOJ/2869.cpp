#include<cstdio>

int main() {

	long long a, b, v;

	scanf("%lld %lld %lld", &a, &b, &v);

    if (a == v) printf("1\n");
    else {
        if ((v - a) % (a - b) == 0) {
            printf("%lld\n", ((v - a) / (a - b)) + 1);
        }
        else {
            printf("%lld\n", ((v - a) / (a - b)) + 2);
        }
    }

	return 0;
}