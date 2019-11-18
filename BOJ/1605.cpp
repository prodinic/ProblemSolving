#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {

    int L;
    char c;
    vector<char> v;
    cin >> L;

    for (int i = 0; i < L; i++) {
        
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    int key = v[0];
    int max = 0;
    for (int i = 1; i < v.size(); i++) {
        
        if (key == v[i]) {
            cnt++;
            if (i == v.size() - 1) {
                if (max < cnt) {

                    max = cnt;
                }
            }
        }
        else {
            if (max < cnt) {
                // cout<<"here"<<endl;
                max = cnt;
            }
            key = v[i];
            cnt = 1;
        }

    }
    cout<<max<<endl;
    return 0;
}