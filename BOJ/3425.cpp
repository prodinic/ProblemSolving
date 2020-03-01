#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#define ll long long int
#define MAX_NUM 1000000000

using namespace std;

int N;

int main() {

    string s;
    stack<ll> st;
    vector<string> v;
    vector<ll> numbers;

    ll x;

    while(1) {
        
        cin >> s;
        
        if (s.compare("QUIT") == 0) {
            
            return 0;
        }
        while (s.compare("END") != 0) {

            if (s.compare("NUM") == 0) {
                
                int tmp;
                cin >> tmp; 
                // cout << "tmp : "<< tmp << endl;
                numbers.push_back(tmp);
            }

            v.push_back(s);
            cin >> s;
        }

        // cout << "numbers list : "; 
        // for (int i = 0; i < numbers.size(); i++) {
        //     cout << numbers[i] << " ";
        // }
        // cout << endl;
        cin >> N;

        for (int i = 0; i < N; i++) {

            ll tmp, first, second;
            cin >> tmp;
            int idx = 0;
            st.push(tmp); 
            int j;
            bool flag = true;
            if (tmp >= 0 && tmp <= MAX_NUM) {
                for (j = 0; j < v.size(); j++) {

                    string opr = v[j];
                    
                    if (opr.compare("NUM") == 0) {
                        // cout << "x : " << x << endl;
                        
                        x = numbers[idx];
                        if (x < 0 || x > MAX_NUM) {
                            flag = false;
                            break;
                        }
                        idx++;
                        st.push(x);
                    }
                    else if (opr.compare("POP") == 0) {

                        if (st.size() <= 0) {
                            flag = false;
                            break;
                        }
                        st.pop();
                    }
                    else if (s.compare("INV") == 0) {
                        if (st.size() == 0 || (st.top() < 0 || st.top() > MAX_NUM)) {
                            flag = false;
                            break;
                        }
                        first = st.top() * (-1);
                        st.pop();
                        st.push(first);
                    }
                    else if (opr.compare("DUP") == 0) {
                        if (st.size() == 0) {
                            flag = false;
                            break;
                        }                        
                        st.push(st.top());
                    }
                    else if (opr.compare("SWP") == 0) {

                        if (st.size() < 2) {
                            flag = false;
                            break;
                        }
                        first = st.top();
                        st.pop();
                        second = st.top();
                        st.pop();
                        st.push(first);  
                        st.push(second);                  
                    }
                    else if (opr.compare("ADD") == 0) {
                        if (st.size() < 2) {
                            flag = false;
                            break;
                        }
                        first = st.top();
                        st.pop();
                        second = st.top();
                        st.pop();
                        if (abs(second + first) > MAX_NUM) {
                            flag = false;
                            break;
                        }
                        st.push(first + second);
                    }
                    else if (opr.compare("SUB") == 0) {
                        if (st.size() < 2) {
                            flag = false;
                            break;
                        }
                        first = st.top();
                        st.pop();
                        second = st.top();
                        st.pop();
                        if (abs(second - first) > MAX_NUM) {
                            flag = false;
                            break;
                        }
                        st.push(second - first);                    
                    }
                    else if (opr.compare("MUL") == 0) {
                        if (st.size() < 2) {
                            flag = false;
                            break;
                        }
                        first = st.top();
                        st.pop();
                        second = st.top();
                        st.pop();
                        if (abs(first * second) > MAX_NUM) {
                            flag = false;
                            break;
                        }
                        st.push(first * second);
                    }
                    else if (opr.compare("DIV") == 0) {
                        ll a;
                        if (st.size() < 2) {
                            flag = false;
                            break;
                        }
                        first = st.top();
                        st.pop();
                        if (first == 0) {
                            flag = false;
                            break;
                        }

                        second = st.top();
                        st.pop();

                        if (first < 0) {
                            first *= -1;
                            if (second > 0) a = (second / first) * (-1);
                            else {
                                second *= -1;
                                a = (second / first);
                            }
                        }
                        else {
                            if (second < 0) {
                                second *= -1;
                                a = (second / first) * (-1);
                                
                            }
                            else a = (second / first);
                        }

                        st.push(a);                    
                    }
                    else if (opr.compare("MOD") == 0) {
                        ll a;
                        if (st.size() < 2) {
                            flag = false;
                            break;
                        }
                        first = st.top();
                        st.pop();
                        if (first == 0) {
                            flag = false;
                            break;
                        }
                        second = st.top();
                        st.pop();
                        if (second < 0) {
                            second *= -1;
                            if (first < 0) {
                                first *= -1;
                                a = (second % first) * (-1);
                            }
                            else {
                                a = (second % first) * (-1);
                            }
                        }
                        else {
                            if (first < 0) {
                                first *= -1;
                                a = second % first;
                            }
                            else {
                                a = second % first;
                            }                        
                        }
                        st.push(a);                                 
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            else {
                flag = false;
            }
            if (st.size() == 1 && (st.top() <= MAX_NUM) && flag == true) cout << st.top() << endl;
            else cout << "ERROR" << endl;

            if (st.size() == 0) continue;
            // cout << st.size() << endl;
            while(!st.empty()) st.pop();
        }

        v.clear();
        cout << endl;
        numbers.clear();
    }
    
    return 0;
}