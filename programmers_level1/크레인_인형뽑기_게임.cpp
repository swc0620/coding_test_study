#include <stack>
#include <vector>
#define NOT_FOUND -1

using namespace std;

int pickPlushie(vector<vector<int>> &board, const int &col) {
    for (int i=0; i<board.size(); ++i) {
        if (board[i][col] > 0) {
            int plushie = board[i][col];
            board[i][col] = 0;
            return plushie;
        }
    }
    return NOT_FOUND; 
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer{ 0 };
    stack<int> bucket;

    for (int move : moves) {
        int plushie = pickPlushie(board, move-1);
        if (plushie == NOT_FOUND) {
            continue;
        }

        if (!bucket.empty() && bucket.top() == plushie) {
            answer += 2;
            bucket.pop();
        } else {
            bucket.push(plushie);
        }
    }

    return answer;
}