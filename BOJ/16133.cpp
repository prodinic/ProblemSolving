#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#define MAX_LEN 100001

using namespace std; 

int N;
string signals;
vector<int> v;
vector<string> numbers;

void printAll() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < numbers[i].size(); j++) {
            cout << numbers[i][j];
        }
        cout << "\n";
    }
}

void init() {
    numbers.push_back("####.##.##.####");
    numbers.push_back("#####");
    numbers.push_back("###..#####..###");
    numbers.push_back("###..####..####");
    numbers.push_back("#.##.####..#..#");
    numbers.push_back("####..###..####");
    numbers.push_back("####..####.####");
    numbers.push_back("###..#..#..#..#");
    numbers.push_back("####.#####.####");
    numbers.push_back("####.####..#..#");
}

char findMatchedNumber(int s, int span, int chunk) {

    for (int number = 0; number < numbers.size(); number++) {
        if (number == 1) continue;
        bool isMatched = true;
        for (int i = 0; i < 15; i++) {
            if (signals.at(i % 3 + chunk * (i / 3)) == numbers[number].at(i)) continue;
            else {
                isMatched = false;
                break;
            }
        }
        if (isMatched) {
            // cout << "number : " << number << "\n";
            return '0' + number;
        }
    }
}

bool isEmptySpace(int idx, int chunk) {
    bool flag = true;
    for (int i = 0; i < N; i += chunk) {
        if (signals[i + idx] == '.') continue;
        else {
            flag = false;
            break;
        }
    }  
    return flag;
}

vector<int> getEmptySpaceIdxList(int chunk) {
    vector<int> v;
    for (int i = 0; i < chunk; i++) {
        if(isEmptySpace(i, chunk)) {
            v.push_back(i);
        }
    }
    return v;
}

string solve(vector<int> empty_space_idx_list) {
    string answer = "";
    for (int i = 0; i < empty_space_idx_list.size() - 1; i++) {
        int from, to;
        if (i == 0) {
            if (empty_space_idx_list[i] != 0) {
                from = 0;
                to = empty_space_idx_list[i];
            }
            else {
                from = empty_space_idx_list[i];
                to = empty_space_idx_list[i + 1];
            }
        }
        else {
            from = empty_space_idx_list[i];
            to = empty_space_idx_list[i + 1];
        }
        cout << "from : " << from << " | to : " << to << endl;
        int span = to - from;
        if (span == 1) continue;
        else if (span == 2) {
            answer.push_back('1');
        }
        else if (span == 3) {
            // cout << "before answer : " << answer << endl;
            int matchedNumber = findMatchedNumber(i, span, N / 5);
            // cout << "matchedNumber : " << matchedNumber << endl;
            answer.push_back('0' + matchedNumber);
            // cout << "after answer : " << answer << endl;
        }
        else {
            break;
        }
        // cout << answer << endl;
    }
    return answer; 
}

int main() {

    cin >> N;
    cin >> signals;
    init();
    // printAll();
    if (N == 5) {
        // cout << "check1" << "\n";
        cout << "1" << "\n";
    } 
    else {
        // cout << "check2" << "\n";
        vector<int> empty_space_idx_list = getEmptySpaceIdxList(N / 5);
        if (empty_space_idx_list.size() == 0) {
            cout << "check4" << endl;
            cout << findMatchedNumber(0, 3, N / 5) << "\n";
        }
        else {
            cout << "check5" << endl;
            cout << solve(empty_space_idx_list) << "\n";
        }
    }

    return 0;
}