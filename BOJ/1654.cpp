#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define ll long long int

using namespace std; 

int N, K;


int main() {

    ll answer = 0;
    ll a;
    cin >> N >> K;
    vector<ll > v;

    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    ll left = 0, right = INT_MAX;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll k = 0;

        for (int i = 0; i < v.size(); i++) {
            k += v[i] / mid;
        }

        if (k < K) {
            right = mid - 1;
        }
        else {
            answer = mid;
            left = mid + 1;
        }
    }


    cout << answer << endl;
    return 0;
}