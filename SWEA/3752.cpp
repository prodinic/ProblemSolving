#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {

    int T, N;
    vector<int> score;
    bool chk[10001] = {false, };
    vector<int> v;

    cin>>T;
    
    for (int i = 1; i <= T; i++) {

        cin>>N;

        for (int j = 0; j < N; j++) {
            
            int tmp;
            cin>>tmp;

            score.push_back(tmp);
        }
        // cout<<"start!"<<endl;

        v.push_back(0); // push 0 for the situation where user cannot solve any problems.
        chk[0] = true;

        for (int j = 0; j < score.size(); j++) {

            int cur = score[j]; // get j-th score
            int len = v.size();

            for (int k = 0; k < len; k++) {
                
                int nxt = v[k] + cur; // sum with already viable number
                // cout<<"next : "<<nxt<<endl;
                if (chk[nxt] == false) {
                    
                    chk[nxt] = true;
                    v.push_back(nxt);
                }
                else {
                    continue;
                }
            }
        }

        cout<<"#"<<i<<" "<<v.size()<<endl;

        memset(chk, false, sizeof(chk));
        score.clear();
        v.clear();
    }


    return 0;
}