#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n; 
    cin >> n; 
    vector<string> v;

    for (int i = 0; i < n + 1; i++) {

        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n + 1; i++) {

        cout << v[i] <<endl;
    }


    return 0;
}