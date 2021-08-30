#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0]; // 정사각형 변의 길이
    int m = board.size();
    int n = board[0].size(); // m x n 배열
    
    for (int i=1; i<m; ++i) { // boundary
        for (int j=1; j<n; ++j) {
            if (board[i][j] == 1) { // 아직 방문 안 한 칸. 0은 정사각형에 포함될 수 X
                board[i][j] = 1 + min(board[i][j-1], min(board[i-1][j-1], board[i-1][j])); // 왼쪽 칸, 왼쪽 위 칸, 위 칸의 값 비교하는 DP 방식, 기존 정사각형 변의 길이에서 더 큰 정사각형 생기므로 하나 더 늘려줌. 만약 0 포함 시 정사각형 생성 불가하므로 변동 X
                answer = max(answer, board[i][j]); // 최대값 갱신
            }
        }
    }

    return answer * answer;
}