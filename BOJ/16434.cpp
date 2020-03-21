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
    
    while(_left < _right) {
    
        ll mid = (_left + _right) / 2;
        // answer = mid;
        bool flag = false;
        ll total = mid;
        ll attack = H;

        for (int i = 0; i < N; i++) {
            int info = v[i].first;
            int power = v[i].second.first;
            int hp = v[i].second.second;

            if (info == 1) {    // attack
                if (hp % attack == 0) {
                    if (total <= ((hp / attack) - 1) * power) {
                        // cout << "test1" << "\n";
                        _left = mid + 1;
                        flag = true;
                        break;
                    }
                    else {
                        total -= ((hp / attack) - 1) * power;
                    }
                }
                else {
                    if (total <= (hp / attack) * power) {
                        // cout << "total : "<<total<< "| test2" << "\n";
                        _left = mid + 1;
                        // cout << "_left : "<<_left << " | right : " <<_right << "\n";
                        flag = true;
                        break;
                    }
                    else {
                        total -= (hp / attack) * power;
                    }
                }
            }
            else {  // potion
                attack += power;
                if (total + hp > mid) total = mid;
                else total += hp;
            }
        }

        if(!flag) _right = mid;
        answer = mid;
        // cout << "answer : "<<answer << "\n";
    }
    answer = (_left + _right) / 2;
    cout << answer << endl;
    return 0;
}