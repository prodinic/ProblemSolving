#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_LEN 101
#define MAX_WEIGHT 100001

using namespace std;

int weight[MAX_WEIGHT] = {0, };
int product[MAX_LEN];
int value[MAX_LEN];
int N, K, W, V;

void dp() {

    for (int j = 0; j < N; j++) {
        for (int i = K; i >= 1; i--) {
            if (i >= product[j]) {
                weight[i] = max(weight[i], weight[i - product[j]] + value[j]);
            }
        }
    }

    cout << weight[K] << endl;
}

int main() {

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        product[i] = W;
        value[i] = V;
    }
    dp();
    return 0;
}