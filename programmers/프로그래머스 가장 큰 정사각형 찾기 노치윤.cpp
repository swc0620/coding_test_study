#include <iostream>
#include<vector>
using namespace std;
int min(int a, int b, int c) {
    if (a > b) {
        if (b > c) return c;
        if (c >= b) return b;
    }
    else {
        if (a > c) return c;
        else return a;
    }
}
int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int dp[1000][1000];
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (i == 0 || j == 0) dp[i][j] = board[i][j];
            if (board[i][j] == 0) dp[i][j] = 0; //
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                if (dp[i][j] > answer) answer = dp[i][j];
            }
        }
    }

    return answer * answer;
}