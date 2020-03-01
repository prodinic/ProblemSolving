#include <iostream>
#include <vector>

#define MAX_NUM 48

using namespace std;

int N;
vector<int> S, P;
int card[MAX_NUM];

bool isTheAnswer() {

    bool ret = true;

    for (int i = 0; i < N; i++) {
        
        if (P[card[i]] == i % 3) {
            continue;
        }
        else {
            ret = false;
            break;
        }
    }

    return ret;
}

int shuffle() {

    int tmp[MAX_NUM];
    for (int i = 0; i < N; i++) {

        tmp[S[i]] = card[i]; 
    }

    for (int i = 0; i < N; i++) {
        card[i] = tmp[i];
    }

    return 1;
}
int main() {

    int tmp;
    cin >> N;
    int answer = 0;

    // P
    for (int i = 0; i < N; i++) {

        card[i] = i;
        cin >> tmp;
        P.push_back(tmp);
    }

    // S 
    for (int i = 0; i < N; i++) {

        cin >> tmp;
        S.push_back(tmp);
    }

    while(true) {
        if (isTheAnswer()) {
            cout << answer << endl;
            return 0;
        }
        else {
            answer += shuffle();
        }
        if (answer > 1e7) {

			answer = -1; 
            break;
		}
    }

    cout << answer << endl;
    return 0;
}