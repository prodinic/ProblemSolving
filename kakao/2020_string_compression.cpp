#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_INT 11111

using namespace std;

int solution(string s) {


    int answer = s.length();
    int span = 1;
    string result;

    for (int stick = 1; stick < s.length() / 2 + 1; stick++) {
        // stick is increasing 
        
        int len = 0; 
        
        for (int i = 0; i < s.length(); i += stick) {
            string from = s.substr(i, stick);
            cout<<"from : "<<from<<" | stick : "<<stick<<" | i = "<<i<<endl;
            int cnt = 1;

            bool flag = 0;
            for (int j = i + stick; j < s.length(); j += stick) {
                
                flag = 1;
                string to = s.substr(j, stick);
                cout<<"to : "<<to<<endl;

                // increase cnt when these are same
                if (from.compare(to) == 0) {
                    cnt++;
                } 
                else {
                    if (cnt / 100 > 0) {
                        len += 3;
                    }
                    else if (cnt / 10 > 0) {
                        len += 2;
                    }
                    else {
                        if (cnt % 10 != 1) {
                            len += 1;
                        }
                    }
                    cout<<cnt<<endl;
                    len += from.length();
                    if (cnt != 1) i += cnt; // move index
                    break;
                }            
            }

            if (flag == 0) len += from.length();
            else {
                if (cnt != 1) {
                    len += cnt;
                    i += cnt; // move index
                }
            }

            cout<<"len : "<<len<<endl;
        }


        answer = min(len, answer);

    }

    cout <<answer<< endl;
    return answer;
}
