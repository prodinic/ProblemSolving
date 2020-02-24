#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 

int compare(int a, int b) {
    return a > b;
}

int main() {

    int answer = 0;
    int N;
    vector<string> vs;
    vector<int> v(26, 0);     // init
    string s;

    cin >> N;

    for (int i = 0; i < N; i++) {
    
        cin >> s;
        vs.push_back(s); 
    }

    for (int i = 0; i < N; i++) {
        int len = vs[i].length();
        int pos = 1;

        for (int j = len - 1; j >= 0; j--) {
            char ch = vs[i][j] - 'A';
            v[ch] += pos;
            pos *= 10;
        }
    }

    sort(v.begin(), v.end(), compare);


    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << endl;
    // }

    for (int i = 9; i >= 0; i--) {
        answer += i * v[9 - i];
    }
    cout << answer << endl;
    
    return 0;
}