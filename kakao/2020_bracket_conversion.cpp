#include <string>
#include <vector>
#include <iostream>

using namespace std;

string getBalancedString(string s) {
    
    int cnt = 0;
    string res;

    for (int i = 0; i < s.length(); i++) {
        
        if (s.at(i) == '(') {
            res.push_back(s.at(i));
            cnt++;
        }
        else {
            res.push_back(s.at(i));
            cnt--;
        }
        
        if (cnt == 0) {
            break; 
        }
    }
    
    return res;
}
bool isRight(string s) {
    int cnt = 0;
    bool check = true;

    for (int i = 0; i < s.length(); i++) {
        
        if (s.at(i) == '(') {
            cnt++;
        }
        else {
            cnt--;
        }

        if (cnt < 0) {
            check = false;
            break; 
        }
    }

    return check;
}
string solution(string p) {
    string answer = "";
    string u, v;

    if (p.length() != 0) {
        u = getBalancedString(p);
        cout<<"u : "<<u<<endl;
        v = p.substr(u.length());
        cout<<"v : "<<v<<endl;

        // execute getBalancedString function continuously 
        if (isRight(u) == true) {
            answer.append(u.append(solution(v)));
        }
        // deal with sentence when it is not balanced
        else {
            string tmp;

            tmp.push_back('(');
            tmp.append(solution(v));
            tmp.push_back(')');

            u.erase(0, 1);
            u.erase(u.length() - 1, 1);
            cout<<"before : "<<u<<endl;
            for (int i = 0; i < u.length(); i++) {
                if (u.at(i) == '(') {
                    u.at(i) = ')';
                }
                else {
                    u.at(i) = '(';
                }
            }

            cout<<"conversion : "<<u<<endl;

            tmp.append(u);
            answer = tmp;
        }
    } 
    cout<<answer<<endl;
    return answer;
}