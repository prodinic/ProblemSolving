#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std; 
ll N, ten[15], answer;
int L;

int getLength(ll a) {

    int len = 0;

    while (a) {
        len++;
        a /= 10;
    }

    return len;
}

ll mul(ll a, ll b, ll md) {
    // Input : two long long int variables and 자릿수 
    // Output : long long in variables whose lenght is 10
    // Description : multiply two long long int variable avoiding from overflow

    ll ret = 0;
    ll ma, mb; // modular a, modular b
    // int len;
    int aPos, bPos = 0;
    // len = getLength(a);

    while (b / ten[bPos]) {
        mb = b / ten[bPos];
        mb %= 10;
        aPos = 0;
        while (aPos + bPos <= md) {

            ma = a / ten[aPos];
            ma %= 10;
            ret += ma * mb * ten[bPos + aPos] % ten[md];
            ret %= ten[md];
            aPos++;
        }
        bPos++;
    }
    
    return ret % ten[md];
}

bool back(int p, ll c) {

    if (p == L) {
        answer = c;
        return 1;   // why does it return 1?
    }

    ll t, tt;

    for (ll i = 0; i < 10; i++) {
        tt = c + i*ten[p];
        t = mul(tt, tt, p + 1);
        t %= ten[p + 1];
        t = mul(t, tt, p + 1);
        t %= ten[p + 1];
        if (N % ten[p + 1] != t) continue;
        if (back(p + 1, c + i*ten[p])) return 1;

    }
}

int main() {

    int T;
    ll t, t2;
    int len = 0;
    
    cin >> T;   // input number of case

    ten[0] = 1; // init

    for (ll i = 1; i < 15; i++) {
        ten[i] = 10 * ten[i - 1];   // init array 
    }

    while (T--) {

        cin >> N;
        L = getLength(N);
        // cout << "length : " << L <<endl;
        back(0, 0);
        cout << answer % ten[L] << endl;
    }

    return 0;
}