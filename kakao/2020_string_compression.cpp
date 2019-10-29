#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();

    vector<string> v;

    int len = s.size();

    for (int span = 1; span < (s.length() / 2) + 1; span++) {

        int size = 0;
        // save every split string into vector data structure
        for (int i = 0; i < s.length(); i += span) {
            
            string tmp = s.substr(i, span);
            // cout<<"tmp : "<<tmp<<endl;
            v.push_back(tmp);
        }

        for (int i = 0; i < v.size(); i++) {

            int cnt = 1;
            if (i == v.size() - 1) {
                size += v[i].length();
                cout<<"here!!"<<endl;
                break;
            }
            for (int j = i + 1; j < v.size(); j++) {
                
                // increase cnt for the same one
                if (v[i].compare(v[j]) == 0) {

                    cnt++;
                    // increase i-idx
                    if (j == v.size() - 1) {
                        if (cnt / 1000 > 0) {
                            size += 4;
                        }
                        else if (cnt / 100 > 0) {
                            size += 3;
                        }
                        else if (cnt / 10 > 0) {
                            size += 2;
                        }
                        else {
                            size += 1;
                        }
                        size += v[i].length();
                        cout<<"from : "<<v[i]<<" | cnt : "<<cnt<<" | size : "<<size<<endl;
                        i += cnt - 1;
                    }
                }
                else {

                    if (cnt / 1000 > 0) {
                        size += 4;
                    }
                    else if (cnt / 100 > 0) {
                        size += 3;
                    }
                    else if (cnt / 10 > 0) {
                        size += 2;
                    }
                    else {
                        if (cnt > 1) size += 1;
                    }

                    size += v[i].length();
                    cout<<"from : "<<v[i]<<" | cnt : "<<cnt<<" | size : "<<size<<endl;
                    i += cnt - 1;
                    break;
                }

            }
            // cout<<v[i]<<endl;
        }

        cout<<"span : "<<span<<" | size : "<<size<<endl;
        if (size < answer) answer = size;

        v.clear();
    }

    return answer;
}