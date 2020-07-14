#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string s;
int K;
bool visited[10];

int countDifferentNumbers() {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (visited[i]) cnt++;
        else continue;
    }
    return cnt;
}

void solve() {
    string ans;
    int len = s.length();
    if (len < K) {
        // copy
        for (auto& arg : s) {
            visited[arg] = true;
            ans.push_back(arg);
        }
        // append
        int idx = 0;
        while(len != K) {
            if (visited[idx]) continue;
            else {
                visited[idx];
                ans.push_back(idx);
                len++;
            }
        }
    }
    else {
        int cnt = countDifferentNumbers();
        if (cnt == K) cout << s << endl;
        else if (cnt > K) {

        }
        else {
            
        }
    }


}

int main() {

    memset(visited, false, sizeof(visited));
    cin >> s >> K;
    for (auto& arg : s) {
        visited[arg - '0'] = true;
    }
    solve();

    return 0;
}