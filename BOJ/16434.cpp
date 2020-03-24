#include <iostream>
#include <limits.h>
#define ll long long int
#define MAX_NUM 123457

using namespace std; 

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    struct info {
        int t, a, h;
    };
    info v[MAX_NUM];

    int N, H, t, a, h, i;

    cin >> N >> H;

    for (int i = 0; i < N; i++) {

        cin >> t >> a >> h;
        v[i].t = t, v[i].a = a, v[i].h = h;
    }

    ll answer = 0, _left = 0, _right = LLONG_MAX, mid, total, attack;
    bool flag;

    while(_left <= _right) {    // 이분 탐색 합니다.
    
        mid = (_left + _right) / 2;
        flag = false;
        total = mid, attack = H;

        for (i = 0; i < N; i++) {
            t = v[i].t;
            a = v[i].a;
            h = v[i].h;

            if (t == 1) {    // 몹을 상대합니다.
                if (h % attack == 0) {  // 공격했을 때, 나머지가 0 입니다.
                    if (total <= ((h / attack) - 1) * a) {  // 내가 몹보다 먼저 죽을 경우, 최소 HP를 늘리고 다시 이분탐색 합니다.
                        _left = mid + 1;
                        flag = true;
                        break;
                    }
                    else total -= ((h / attack) - 1) * a;   // 남은 채력을 저장합니다.
                }
                else {  // 공격했을 때, 나머지가 0이 아닙니다.
                    if (total <= (h / attack) * a) {    // 내가 몹보다 먼저 죽을 경우, 최소 HP를 늘리고 다시 이분탐색 합니다.
                         _left = mid + 1;
                        flag = true;
                        break;
                    }
                    else total -= (h / attack) * a; // 남은 체력을 저장합니다.
                }
            }
            else {  // potion
                attack += a;
                if (total + h > mid) total = mid;
                else total += h;
            }
        }
        if(!flag) { // 모든 방을 돌고 난 후, 최소 HP를 줄이고 다시 이분탐색 합니다.
            _right = mid - 1;
            answer = mid;
        }
    }

    cout << answer << "\n";
    return 0;
}