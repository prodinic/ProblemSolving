#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define pp pair<int, pair<int, int > >
#define ll long long int

using namespace std; 

int N, H;
int t, a, h;
vector<pp> v;

int main() {

    ll answer = 0;
    cin >> N >> H;

    for (int i = 0; i < N; i++) {

        cin >> t >> a >> h;
        v.push_back(make_pair(t, make_pair(a, h)));
    }

    ll _left = 0, _right = LLONG_MAX;
    while(_left <= _right) {
        ll mid = (_left + _right) / 2;

        for (int i = 0; i < N; i++) {
            int info = v[i].first;
            int power = v[i].second.first;
            int hp = v[i].second.second;

            if (info == 0) {
                if (hp % H == 0) {
                    if (mid < (hp / H)) {
                        _left = mid + 1;
                        break;
                    }
                }
                else {
                    if (mid < (hp / H) + 1) {
                        _left = mid + 1;
                        break;
                    }
                }
            }
            else {
                H += power;
                mid += hp;
            }
        }
        _right = mid - 1;
        answer = mid;
        cout << "answer : "<<answer << endl;
    }

    cout << answer << endl;
    return 0;
}