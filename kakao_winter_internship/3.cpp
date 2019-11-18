#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    
    int answer = 0;

    vector<int> g(user_id.size());
    vector<vector<string>> v(banned_id.size());

    for (int i = 0; i < banned_id.size(); i++) {

        string b = banned_id[i];

        for (int j = 0; j < user_id.size(); j++) {
            
            string s = user_id[j];
            bool chk = true;

            if (b.length() == s.length()) {

                for (int k = 0; k < b.length(); k++) {
                    if (b.at(k) == '*') {
                        continue;
                    }
                    else {
                        if (b.at(k) == s.at(k)) {
                            continue;
                        }
                        else {
                            chk = false;
                        }
                    }
                }
            }
            else {
                continue;
            }

            if (chk) {
                v[i].push_back(s);
            }
            else {
                continue;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << "i : " <<i <<endl;
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] <<endl;
        }
    }

    for (int i = 0; i < user_id.size(); i++) {
        g[i] = 0;
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {

            str s = v[i][j];

            for (int k = 0; k < user_id.size(); k++) {
                if (s.compare(user_id[k]) == 0) {
                    g[k]++;
                }
            }
        }
    }
    
    
    return answer;
}