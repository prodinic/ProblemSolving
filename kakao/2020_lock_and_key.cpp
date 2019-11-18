#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int>> rotate(vector<vector<int>> v) {
    // Input : key pair
    // Output : turned key pair
    // Description : turn clockwise 90 degrees

    int size = v.size();

    vector<vector<int>> res(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i].push_back(v[size - j - 1][i]); // what happen to this index?      
        }
    }

    return res;
}

vector<vector<int>> enlargeKey(vector<vector<int>> v) {

    int size = v.size();

    vector<vector<int>> res(size + 2 * (size - 1));

    for (int i = 0; i < size + 2 * (size - 1); i++) {
        for (int j = 0; j < size  + 2 * (size - 1); j++) {

            if (size - 1 <= i && i < size - 1 + size) {
                if (size - 1 <= j && j size - 1 + size) {

                    res[i].push_back(v[i - size + 1][j - size + 1]);
                }
                else {
                    res[i].push_back(0);
                }
            }
            else {
                res[i].push_back(0);
            }
        }
    }

    return res;
}


int getNumberOfPeak(vector<vector<int>> v) {

    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 1) {
                cnt++;
            }
            else {
                continue;
            }
        }
    }

    return cnt;
}

int getNumberOfFloor(vector<vector<int>> v) {
    
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 0) {
                cnt++;
            }
            else {
                continue;
            }
        }
    }
    return cnt;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    bool answer = false;
    
    if (getNumberOfPeak(key) >= getNumberOfFloor(lock)) {

        vector<vector<int>> en = enlargeKey(key);
        int en_key_size = en.size();
        int key_size = key.size();

        for (int x = 0; x < en_key_size - key_size; x++) {
            for (int y = 0; y < en_key_size - key_size; y++) {
                
                key.clear();
                // make new key
                for (int a = 0; a < key_size; a++) {
                    for (int b = 0; b < key_size; b++) {

                        key[a].push_back(en[x + a][y + b]);
                    }
                }
                
                //compare key with lock
                for (int t = 0; t < 4; t++) {
                    key = rotate(key); // rotate key

                    for (int i = 0; i + key_size <= lock_size; i++) {
                        for (int j = i; j < i + key_size; j++) {    
                            for (int k = 0; k < key_size; k++) {
                                for (int l = 0; l < key_size; l++) {
                                    
                                    if (key[k][l] == 0) {
                                        continue;
                                    }
                                    else {
                                        
                                    }

                                }
                            }

                        }
                    } 
                }
            }
        }
        int en_key_size = en.size();
        int key_size = key.size();
        int lock_size = lock.size();
    }

    return answer;
}