#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 99999999

using namespace std;

bool base[4] = {0, };
int scores = 0;
int sum = 0;
int out_count = 0;
int cur = 0;
bool finish = false;
int res = 0;

// bool isOnGoing = false;

void onBase(int r) {

    // out
    if (r == 0) {
        if (out_count == 2) {
            out_count = 0;
            scores += sum;
            finish = true;
            sum = 0;
            for (int i = 0; i < 4; i++) {
                base[i] = 0;
            }
        }
        else {
            out_count++;
        }
    }
    // 1 base
    else if (r == 1) {
        for (int i = 3; i > 0; i--) {
            if (base[i]) {
                if (i == 3) {
                    base[i] = false;
                    sum++;
                }
                else {
                    base[i + 1] = true;
                    base[i] = false;
                }
            }
            else {
                continue;
            }
        }
        base[1] = true;
    }
    else if (r == 2) {
        for (int i = 3; i > 0; i--) {
            if (base[i]) {
                if (i == 3 || i == 2) {
                    base[i] = false;
                    sum++;
                }
                else {
                    base[i + 2] = true;
                    base[i] = false;
                }
            }
            else {
                continue;
            }
        }
        base[2] = true;
    }
    // 3 base
    else if (r == 3) {
        for (int i = 3; i > 0; i--) {
            if (base[i]) {
                base[i] = false;
                sum++;                
            }
            else {
                continue;
            }
        }
        base[3] = true;
    }
    // home run!
    else {
        for (int i = 3; i > 0; i--) {
            if (base[i]) {
                base[i] = false;
                sum++;
            }
            else {
                continue;
            }
        }
        sum++;
    }
}

int main() {

    int N, tmp;
    int map[55][9];

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {

            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    for (int k = 0; k < 9; k++) {
        cur = k;
        cout<<"-- start -- with k : "<<cur<<endl;
        for (int i = 0; i < N; i++) {

            while (1) {
                
                cur = cur % 9;
                // 1, 2, 3
                if (cur < 3) {
                    onBase(map[i][cur + 1]);
                }
                // 4
                else if (cur == 3) {
                    onBase(map[i][0]);
                }
                // 5, 6, 7, 8, 9
                else {
                    onBase(map[i][cur]);
                }
                cout<<"cur pos : "<<cur<<" | out count : "<<out_count<<endl;

                cur++;
                if (finish) {
                    finish = false;
                    break;
                }
            }
        }

        if (res < scores) {
            res = scores;
            scores = 0;
        }
    }

    cout<<res<<endl;

    return 0;
}