#include<cstdio>
#include<queue>

using namespace std;

long long func(int k) {

	long long res = 1;
	for (int i = 1; i <= k; i++) {

		res = res * 2;
	}

	return res;
}

void hanoi(int start, int end, int from, int to) {

	if (end == start) {

		printf("%d %d\n", from, to);
		return;
	}

	if (start != end) {

		if (from == 1 && to == 2) {

			hanoi(start, end - 1, 1, 3);
			hanoi(end, end, 1, 2);
			hanoi(start, end - 1, 3, 2);
		}

		else if (from == 1 && to == 3) {

			hanoi(start, end - 1, 1, 2);
			hanoi(end, end, 1, 3);
			hanoi(start, end - 1, 2, 3);
		}

		else if (from == 2 && to == 1) {

			hanoi(start, end - 1, 2, 3);
			hanoi(end, end, 2, 1);
			hanoi(start, end - 1, 3, 1);
		}

		else if (from == 2 && to == 3) {

			hanoi(start, end - 1, 2, 1);
			hanoi(end, end, 2, 3);
			hanoi(start, end - 1, 1, 3);
		}

		else if (from == 3 && to == 1) {

			hanoi(start, end - 1, 3, 2);
			hanoi(end, end, 3, 1);
			hanoi(start, end - 1, 2, 1);
		}

		else if (from == 3 && to == 2) {

			hanoi(start, end - 1, 3, 1);
			hanoi(end, end, 3, 2);
			hanoi(start, end - 1, 1, 2);
		}
	}
}
int main() {

	int k;

	scanf("%d", &k);

	printf("%lld\n", func(k) - 1);
	
	if (k <= 20) hanoi(1, k, 1, 3);

	return 0;
}