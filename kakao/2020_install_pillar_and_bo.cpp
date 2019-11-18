#include <string>
#include <vector>

using namespace std;

int map[111][111] = {0, };

bool isPilarAvailable(int n, int x, int y) {

    bool ret = false;

    if (y == 0) {
        
        ret = true;
    }
    else {

        if (map[x][y - 1] == 1 || map[x][y - 1] == 3) {
            ret = true;
        }
        if (x == 0) {
            if (map[x][y] == 2 && (map[x + 1][y - 1] == 1 || map[x + 1][y - 1] == 3)) {
                ret = true;
            }
        }
        else {
            // right side
            if (map[x][y] == 2 && (map[x + 1][y - 1] == 1 || map[x + 1][y - 1] == 3)) {
                ret = true;
            }
            // left side
            if (map[x - 1][y] == 2 && (map[x - 1][y - 1] == 1 || map[x - 1][y - 1] == 3)) {
                ret = true;
            }
        }
    }

    return ret;
}

bool isBoAvailable(int n, int x, int y) {

    bool ret = false;

    if (y != 0) {
       if ((map[x][y - 1] == 1 || map[x][y - 1] == 3) || (map[x + 1][y - 1] == 1 || map[x + 1][y - 1] == 3)) {
           ret = true;
       }
       if (x == 0) {

           ret = false;
       }
       else if (x == n) {

           ret = false;
       }
       else {
           if (map[x - 1][y] >= 2 && map[x + 1][y] >= 2) {
               ret = true;
           }
       }
    }

    return ret;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++) {
        
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        // install whatever the building is
        if (b == 1) {
            // first stage
            if (y == 0) {
                answer.push_back(x);
                answer.push_back(y);
                answer.push_back(a);                
            }
            else {
                if (x == 0) {
                    if (map[x][y - 1] == 1 || map[x][y - 1] == 3) {
                        map[x][y] += a;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    if (map[x][y - 1] == 1 || map[x][y - 1] == 3) {
                        map[x][y] += a;
                    }
                    else {
                        if (map[x - 1][y] >= 2 && map[x][y] >= 2) {
                            if (a == 1) {
                                map[x][y] = a;
                            }
                            else {

                            }
                        }
                    }
                }
            }
            // case for nothing
            if (map[x][y] == 0) {
                if ()
                map[x][y] += a;                 
            }
            // case for 기둥
            else if (map[x][y] == 1) {
                if (a == 1) {
                    map[x][y] += 2;    
                }
            }
            // case for 보
            else if (map[x][y] == 2) {
                if (a == 0) {
                    map[x][y] += 1;
                }
            }
            // skip for the case both 기둥 and 보
            else {
                continue;
            }

            answer.push_back(x);
            answer.push_back(y);
            answer.push_back(a);
        }

    }

    return answer;
}