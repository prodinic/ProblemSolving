#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#define ll long long

using namespace std;

int n;
vector<ll> h;

ll solve(int left, int right) {

    if (left == right) return h[left];
    int mid = (left + right) / 2;
    ll ret = max(solve(left, mid), solve(mid + 1, right));
    int lo = mid, hi = mid + 1;
    ll height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);

    while(left < lo || hi < right) {
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            hi++;
            height = min(height, h[hi]);
        }
        else {
            lo--;
            height = min(height, h[lo]);
        }

        ret = max(ret, height * (hi - lo + 1));
    }

    return ret;
}

int main() {
    
    int tmp;

    while(1) {
        scanf("%d", &n);
        if (n == 0) break;
        else {
            for (int i = 0; i < n; i++) {
                scanf("%d", &tmp);
                h.push_back(tmp);
            }
            printf("%lld\n", solve(0, n - 1));
        }
        h.clear();
    }

    return 0;
}