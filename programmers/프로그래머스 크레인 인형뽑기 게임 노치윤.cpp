#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> temp;
    int n = board.size();
    for (int i = 0; i < moves.size(); i++) {
        int y = moves[i] - 1;
        for (int k = 0; k < n; k++) {
            if (board[k][y] != 0) {
                if (temp.size() != 0 && temp.back() == board[k][y]) {
                    temp.pop_back();
                    answer += 2;
                    board[k][y] = 0;
                    break;
                }
                if (temp.size() == 0 || temp.back() != board[k][y]) {
                    temp.push_back(board[k][y]);
                }
                board[k][y] = 0;
                break;
            }
        }
    }
    return answer;
}