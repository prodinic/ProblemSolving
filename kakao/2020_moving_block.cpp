#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0 -1, 0, 1};

int solution(vector<vector<int>> board) {

    int answer = 0;
    int stage = 0;
    bool checked[111][111] = {false, };

    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;

    // initialize init point
    queue.push(make_pair(make_pair(make_pair(0, 0), make_pair(0, 1))), 0);

    // check visited 
    checked[0][0] = true;
    checked[0][1] = true;

    while(!s.empty()) {

        pair<int, int> p1 = q.front().first.first;
        pair<int, int> p2 = q.front().first.second;
        int cur_stage = q.front().second;

        q.pop(); // eliminate first one

        for (int i = 0; i < 4; i++) {
            
            int p1_x = p1.first + dx[i];
            int p1_y = p1.seocnd + dy[i];

            int p2_x = p1.first + dx[i];
            int p2_y = p1.seocnd + dy[i];

            if (board[p1_x][p1_y] == 1 || board[p2_x][p2_y] == 1)   // check there are any wall
            if (checked[p1_x][p1_y] == 1 && checked[p2_x][p2_y] == 1)   // check if it has already been before
            if (p1_x < 0 || p1_x)   // check next step is out 

        }      

        // case for horizontal
        if (p1.first == p2.first) {
            
            if (checked[p1.first + 1])
            if (checked[p1.first][p1.second - 1] == 1) continue;
            if (checked[p1.first][p1.second + 1] == 1) continue;
        }

        // case for vertical 
        if (p1.second == p2.second) {


        } 
    }
    return answer;  
}