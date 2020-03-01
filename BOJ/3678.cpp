#include <iostream>
#include <vector>
#include <string.h>

#define MAX_LEN 10001
#define STONE_NUM 6

using namespace std; 

int v[MAX_LEN];
int stone[STONE_NUM] = {0, };

vector<int> two, four, six, eight, ten, twelve;

int oneOutOfThree(int first, int second, int third) {

    vector<int> v1;

    for (int i = 1; i <= 5; i++) {

        if (i != first && i != second && i != third) {
            v1.push_back(i);
        }
    }
    if (v1.size() == 2) {

        if (stone[v1[0]] > stone[v1[1]]) {
            return v1[1];
        }
        else if (stone[v1[0]] < stone[v1[1]]) {
            return v1[0];
        }
        else {
            if (v1[0] > v1[1]) {
                return v1[1];
            }
            else {
                return v1[0];
            }
        }
    }
    else if (v1.size() == 3) {
        if (stone[v1[0]] > stone[v1[1]]) {
            if (stone[v1[1]] < stone[v1[2]]) {
                return v1[1];
            }
            else if (stone[v1[1]] > stone[v1[2]]) {
                return v1[2];
            }
            else {
                if (v1[1] > v1[2]) {
                    return v1[2];
                }
                else {
                    return v1[1];
                }
            }
        }
        else if (stone[v1[0]] < stone[v1[1]]) {
            if (stone[v1[0]] < stone[v1[2]]) {
                return v1[0];
            }
            else if (stone[v1[0]] > stone[v1[2]]) {
                return v1[2];
            }
            else {
                if (v1[0] > v1[2]) {
                    return v1[2];
                }
                else {
                    return v1[0];
                }
            }
        }
        else {
            if (v1[0] > v1[1]) {
                if (stone[v1[1]] < stone[v1[2]]) {
                    return v1[1];
                }
                else if (stone[v1[1]] > stone[v1[2]]) {
                    return v1[2];
                }
                else {
                    if (v1[1] > v1[2]) {
                        return v1[2];
                    }
                    else {
                        return v1[1];
                    }
                }
            }
            else {
                if (stone[v1[0]] < stone[v1[2]]) {
                    return v1[0];
                }
                else if (stone[v1[0]] > stone[v1[2]]) {
                    return v1[2];
                }
                else {
                    if (v1[0] > v1[2]) {
                        return v1[2];
                    }
                    else {
                        return v1[0];
                    }
                }
            }
        }
    }
    else if (v1.size() == 4) {
        // cout << "hey hey" << endl; 
        int a = v1[0];
        for (int i = 1; i < v1.size(); i++) {
            if (stone[a] == stone[v1[i]]) {
                if (a > v1[i]) {
                    a = v1[i];
                }
            }
            else if (stone[a] < stone[v1[i]]) {
                continue;
            }
            else {
                a = v1[i];
            }
        }
        // for (int i = 0; i < v1.size(); i++) {
        //     cout << v1[i] << " ";
        // }
        // cout << endl;
        // cout << "a : "<< a << endl;
        return a;
    }
}

int oneOutOfTwo(int first, int second) {

    vector<int> v1;

    for (int i = 1; i <= 5; i++) {

        if (i != first && i != second) {
            v1.push_back(i);
        }
    }

    // for (int i = 0; i < v1.size(); i++) {
    //     cout << v1[i] << " ";
    // }
    // cout << endl;
    if (v1.size() == 3) {
        if (stone[v1[0]] > stone[v1[1]]) {
            if (stone[v1[1]] < stone[v1[2]]) {
                return v1[1];
            }
            else if (stone[v1[1]] > stone[v1[2]]) {
                return v1[2];
            }
            else {
                if (v1[1] > v1[2]) {
                    return v1[2];
                }
                else {
                    return v1[1];
                }
            }
        }
        else if (stone[v1[0]] < stone[v1[1]]) {
            if (stone[v1[0]] < stone[v1[2]]) {
                return v1[0];
            }
            else if (stone[v1[0]] > stone[v1[2]]) {
                return v1[2];
            }
            else {
                if (v1[0] > v1[2]) {
                    return v1[2];
                }
                else {
                    return v1[0];
                }
            }
        }
        else {
            if (v1[0] > v1[1]) {
                if (stone[v1[1]] < stone[v1[2]]) {
                    return v1[1];
                }
                else if (stone[v1[1]] > stone[v1[2]]) {
                    return v1[2];
                }
                else {
                    if (v1[1] > v1[2]) {
                        return v1[2];
                    }
                    else {
                        return v1[1];
                    }
                }
            }
            else {
                if (stone[v1[0]] < stone[v1[2]]) {
                    return v1[0];
                }
                else if (stone[v1[0]] > stone[v1[2]]) {
                    return v1[2];
                }
                else {
                    if (v1[0] > v1[2]) {
                        return v1[2];
                    }
                    else {
                        return v1[0];
                    }
                }
            }
        }
    }
    else if (v1.size() == 4) {
        // cout << "hey hey" << endl; 
        int a = v1[0];
        for (int i = 1; i < v1.size(); i++) {
            if (stone[a] == stone[v1[i]]) {
                if (a > v1[i]) {
                    a = v1[i];
                }
            }
            else if (stone[a] < stone[v1[i]]) {
                continue;
            }
            else {
                a = v1[i];
            }
        }

        // cout << "stone : "<< endl;
        // for (int i = 1; i < 6; i++) {
        //     cout << stone[i] <<" ";
        // }
        // cout << endl;
        // for (int i = 0; i < v1.size(); i++) {
        //     cout << v1[i] << " ";
        // }
        // cout << endl;
        // cout << "a : "<< a << endl;
        return a;

        
    }
}

int main() {

    int c, n;

    int num = 0;
    int diff = 1;
    while (num <= 10000) {
        num += diff;
        two.push_back(num);
        diff += 6;
    }

    num = 0;
    diff = 2;
    while (num <= 10000) {
        num += diff;
        twelve.push_back(num);
        diff += 6;
    }
    num = 0;
    diff = 3;
    while (num <= 10000) {
        num += diff;
        ten.push_back(num);
        diff += 6;
    }
        num = 0;
    diff = 4;
    while (num <= 10000) {
        num += diff;
        eight.push_back(num);
        diff += 6;
    }

        num = 0;
    diff = 5;
    while (num <= 10000) {
        num += diff;
        six.push_back(num);
        diff += 6;
    }

        num = 0;
    diff = 6;
    while (num <= 10000) {
        num += diff;
        four.push_back(num);
        diff += 6;
    }

    // cout << "---" << endl;
    
    bool flag = true;
    v[0] = 1;
    stone[v[0]] += 1;
    int cnt;
    for (int cycle = 0; ; cycle++) {

        int t2 = two[cycle];
        int t12 = twelve[cycle];
        int t10 = ten[cycle];
        int t8 = eight[cycle];
        int t6 = six[cycle];
        int t4 = four[cycle];

        if (cycle == 0) {

            v[1] = 2;
            stone[v[1]] += 1;
            v[2] = 3;
            stone[v[2]] += 1;
            v[3] = 4;
            stone[v[3]] += 1;
            v[4] = 5;
            stone[v[4]] += 1;
            v[5] = 2;
            stone[v[5]] += 1;
            v[6] = 3;
            stone[v[6]] += 1;

        } 
        else {
            // cout << "from : "<<four[cycle - 1] + 1 << " | to : " << t4 << endl;
            for(cnt = four[cycle - 1] + 1; cnt <= t4; cnt++) {

                if (cnt > MAX_LEN) {
                    flag = false;
                    break;
                }

                int first, second, third, cur;
                if (cnt == four[cycle - 1] + 1) {
                    first = (cnt - 1);
                    if (cycle == 1) second = 1;
                    else second = four[cycle - 2] + 1;

                    cur = oneOutOfTwo(v[first], v[second]);
                    v[cnt] = cur;
                    // cout << "first : "<< v[first] << " | second : "<< v[second] << endl;
                    // cout << "cnt : " << cnt << " | cur : " << cur << endl;
                    stone[cur]++;                     
                }
                else if (cnt < t2) {

                    first = (cnt - 1);
                    diff = cnt - four[cycle - 1];
                    second = four[cycle - 2] + diff;
                    third = second - 1;

                    cur = oneOutOfThree(v[first], v[second], v[third]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }        
                    v[cnt] = cur;
                    stone[cur]++;    
                }
                else if (cnt == t2) {
                    first = (cnt - 1);
                    second = two[cycle - 1];

                    cur = oneOutOfTwo(v[first], v[second]);
                    v[cnt] = cur;
                    stone[cur]++;    
                }
                else if (cnt < t12) {
                    first = (cnt - 1);
                    diff = cnt - t2;
                    second = two[cycle - 1] + diff;
                    third = second - 1;

                    cur = oneOutOfThree(v[first], v[second], v[third]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }                          
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt == t12) {
                    first = (cnt - 1);
                    second = twelve[cycle - 1];

                    cur = oneOutOfTwo(v[first], v[second]);
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt < t10) {
                    first = (cnt - 1);
                    diff = cnt - t12;
                    second = twelve[cycle - 1] + diff;
                    third = second - 1;

                    cur = oneOutOfThree(v[first], v[second], v[third]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }        
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt == t10) {
                    first = (cnt - 1);
                    second = ten[cycle - 1];

                    cur = oneOutOfTwo(v[first], v[second]);
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt < t8) {
                    first = (cnt - 1);
                    diff = cnt - t10;
                    second = ten[cycle - 1] + diff;
                    third = second - 1;

                    cur = oneOutOfThree(v[first], v[second], v[third]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }        
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt == t8) {
                    first = (cnt - 1);
                    second = eight[cycle - 1];

                    cur = oneOutOfTwo(v[first], v[second]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }                    
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt < t6) {
                    first = (cnt - 1);
                    diff = cnt - t8;
                    second = eight[cycle - 1] + diff;
                    third = second - 1;
                   
                    cur = oneOutOfThree(v[first], v[second], v[third]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }        
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt == t6) {
                    first = (cnt - 1);
                    second = six[cycle - 1];

                    cur = oneOutOfTwo(v[first], v[second]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }        
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt < t4) {
                    first = (cnt - 1);
                    diff = cnt - t6;
                    second = six[cycle - 1] + diff;
                    third = second - 1;

                    cur = oneOutOfThree(v[first], v[second], v[third]);

                    if (cnt == 826) {
                        cout << "first : "<< v[first] << " | second : "<< v[second] << " | third : " << v[third] << endl;
                        cout << "cnt : " << cnt << " | cur : " << cur << endl;

                        cout << "stone : ";
                        for (int k = 1; k <= 5; k++) {
                            cout << stone[k] << " ";
                        }
                        cout << endl;
                    }        
                    v[cnt] = cur;
                    stone[cur]++;   
                }
                else if (cnt == t4) {
                    first = (cnt - 1);
                    second = four[cycle - 1];

                    cur = oneOutOfTwo(v[first], v[second]);
                    v[cnt] = cur;
                    stone[cur]++;   
                }
            }
        }
        if (!flag) break;
    }

    // cout << "completed!" << endl;

    
    // cin >> c;
    // for (int i = 0; i < c; i++) {

    //     cin >> n;
    //     cout << v[n - 1] << endl;
    // }

    for (int i = 0; i < 831; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}