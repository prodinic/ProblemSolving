#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;

    vector<int> q;

    for (int i = 0; i < moves.size(); i++) {

        int cur_col = moves[i] - 1;

        for (int j = 0; j < board.size(); j++) {
            
            int top_character = board[j][cur_col];
            
            for (int k = 0; k < q.size(); k++) {
                cout << "q list : ";
                cout << q[k] << " ";
            }
            cout << endl;
            
            if (top_character == 0) {
                continue;
            }
            else {
                q.push_back(top_character);
                board[j][cur_col] = 0;
                break;
            }
        }
        
        if (q.size() == 0 || q.size() == 1) {
            continue;
        }
        else {
            if (q[q.size() - 2] == q[q.size() - 1]) {
                q.pop_back();
                q.pop_back();
                // cout << "top_character : "<<top_character<<endl;
                answer += 2;
            }
        }
    }
    
    return answer;
}