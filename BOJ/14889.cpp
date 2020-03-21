#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#define MAX_LEN 22
#define INF 987654321

using namespace std; 

int arr[MAX_LEN * MAX_LEN] = {0, }; 
int N;
bool compare(int a, int b) {
    if (a > b) return true;
    else return false;
}
void printAll() {
    
    for (int i = 0; i < N * N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
void solve() {
    int answer = INF;
    for (int i = 0; i < ((N * N - N) / 2) - 1; i++) {
        int j = i + 1;

        if (answer > arr[i] + arr[j]) answer = abs(arr[i] - arr[j]);
    }
    cout << answer << endl;
    return;
}
int main() {

    int a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N;j ++) {
            cin >> a;
            if (i == j) continue;

            if (i < j) {    // upper right
                arr[N * i + j] += a;
            }
            else {  // downside left 
                arr[N * j + i] += a;
            }
        }
    }

    sort(arr, arr + (N * N), compare);
    solve();
    // printAll();
    return 0;
}