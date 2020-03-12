#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>
#define MAX_LEN 101

using namespace std;

int map[MAX_LEN][MAX_LEN];
int arr[MAX_LEN];
bool constructed[MAX_LEN];
int N, L;

bool doesGoUp(int pos) {

    int tail_height, head_height;

    for (int i = pos - L + 1; i <= pos; i++) {

        if (constructed[i] == true) return false;
        if (i < 0 || i >= N) return false;

        if (i == pos - L + 1) {
            
            tail_height = arr[i];
        }
        else {
            head_height = arr[i];

            if (abs(tail_height - head_height) != 0) {
                return false;
            }
            else {
                continue;
            }
        }
    }

    for (int i = pos - L + 1; i <= pos; i++) {
        constructed[i] = true;
    }

    return true;
}

bool doesGoDown(int pos) {

    int tail_height, head_height;

    for (int i = pos; i < pos + L; i++) {

        if (i < 0 || i >= N) return false;

        if (i == pos) {
            
            tail_height = arr[i];
        }
        else {
            head_height = arr[i];

            if (abs(tail_height - head_height) != 0) {
                return false;
            }
            else {
                continue;
            }ㅋ`
        }
    }

    for (int i = pos; i < pos + L; i++) {
        constructed[i] = true;
    }

    return true;
}

bool isPossible() {

    bool ret = true;
    int from = 0, to;
    int cur_height = arr[from], next_height;

    for (to = 1; to < N; to++) {

        next_height = arr[to];

        if (abs(cur_height - next_height) == 0) {
            
            from = to;
            continue;
        }
        else if (abs(cur_height - next_height) == 1) {
            
            // case for ascending
            if (cur_height - next_height < 0) {
                // 1. Check the number of cells same length as L from 'from - L' to 'from' 
                // 2. Return false if the length of cells which have same height is shorter than L, return true if it is same or longer than that
                // 3. Move 'from' to 'to' and let 'to' be on 'to + 1'

                if (!doesGoUp(from)) return false;
                from = to;
                cur_height = arr[from];
            }
            // case for descending
            else {
                // 1. Check the number of cells as same length as L from 'to' to 'to + L'
                // 2. Return false 
                // 2-1. If any of them is visited, return false
                // 3. Move '

                if (!doesGoDown(to)) return false;
                from = to + L - 1;
                to = from;
                cur_height = arr[from];
            }
        }
        else {
            
            ret = false;
            return ret;
        }
    }

    return ret;
}

int main() {

    cin >> N >> L;
    int answer = 0;

    // input 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    // case for horizontal
    for (int i = 0; i < N; i++) {

        memset(constructed, false, sizeof(constructed));
        
        for (int j = 0; j < N; j++) {
            
            arr[j] = map[i][j];
        }

        if (isPossible()) {
            // for (int j = 0; j < N; j++) {
                
            //     cout << map[i][j] << " ";
            // }           
            // cout << endl;
            answer++;
        }
        else {
            continue;
        }
    }

    // case for vertical 
    for (int i = 0; i < N; i++) {

        memset(constructed, false, sizeof(constructed));

        for (int j = 0; j < N; j++) {
            
            arr[j] = map[j][i];
        }

        if (isPossible()) {
            // for (int j = 0; j < N; j++) {
                
            //     cout << map[j][i] << " ";
            // }           
            // cout << endl;
            answer++;
        }
        else {
            continue;
        }
    }

    cout << answer << endl;

    return 0;
}