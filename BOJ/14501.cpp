#include <stdio.h>
#include <vector>
#define p pair<int, int>

using namespace std;

void solve() {




}

int main() {

    int N;
    int a, b;
    vector<p> v;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }

    solve();
    return 0;
}