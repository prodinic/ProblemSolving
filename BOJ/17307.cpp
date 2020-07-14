#include <stdio.h> 
#include <limits.h>
#include <string.h>
#include <algorithm>
#define MAX_NUM 250001
#define ll long long

using namespace std;

int buttons[MAX_NUM];
int left_to_right[MAX_NUM];
int right_to_left[MAX_NUM];
int c, n;

int main() {

    memset(left_to_right, 0, sizeof(left_to_right));
    memset(right_to_left, 0, sizeof(right_to_left));
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &buttons[i]);
    }   // input

    ll left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            if (buttons[i - 1] >= buttons[i]) {
                right_to_left[i] = buttons[i - 1] - buttons[i];
            }
            else {
                right_to_left[i] = c - (buttons[i] - buttons[i - 1]);
            }
            // left += right_to_left[i];
        }   // left
        if (i < n - 1) {
            if (buttons[i] <= buttons[i + 1]) {
                left_to_right[i] = buttons[i + 1] - buttons[i];
            }
            else {
                left_to_right[i] = c - (buttons[i] - buttons[i + 1]);
            }
            right += left_to_right[i];
        }   // right
    }

    ll res = LLONG_MAX;
    int button = 1;
    for (int i = 0; i < n; i++) {
        left += right_to_left[i];
        ll steps = max(left, right);
        if (res > steps) { 
            button = i + 1;
            res = steps;
        }
        right -= left_to_right[i];
    }

    printf("%d\n%lld\n", button, res);
    return 0;
}
