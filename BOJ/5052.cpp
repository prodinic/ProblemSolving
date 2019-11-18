#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 

bool isAvailable(vector<string> s, int n) {

    bool ret = true;  
    // cout<<"vector size : "<<s.size()<<endl;

    for (int i = 0; i < s.size() - 1; i++) {
        string s1 = s[i];
        string s2 = s[i + 1]; 

        if (s2.length() == s1.length()) {
            if (s2.compare(s1) == 0) {
                ret = false;
                break;
            }
            else {
                continue;
            }
        }
        else if (s2.length() > s1.length()) {
            if (s1.compare(s2.substr(0, s1.length())) == 0) {
                ret = false;
                break;
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }

    return ret;

}
int main() {

    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++) {


        cin >> n;
        vector<string> s;

        for (int j = 0; j < n; j++) {
            
            string str;

            cin >> str;
            s.push_back(str);
        }

        sort(s.begin(), s.end());

        // for (int j = 0; j < s.size(); j++) {
        //     cout << s[j]<<endl;
        // }

        bool ret;
        if (n == 1) {
            ret = true;
        }
        else {
            ret = isAvailable(s, n);
        }

        s.clear();

        if (ret == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" <<endl;
        }
    }

    return 0;
}