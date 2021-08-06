#include <string>
#include <vector>

using namespace std;

int M, N;

const int dx[3] = { 1,1,0 }; // 오른쪽, 오른쪽 아래, 아래
const int dy[3] = { 0,-1,-1 };

bool isSquare(int x, int y, const vector<string> &board) {
    for (int i=0; i<3; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<0 || ny <0 || nx>=M || ny>=N) // 경계 벗어남
            return false;
        if (board[x][y] != board[nx][ny]) // 같은 모양이 아님
            return false;
    }
    return true;
}

int numEraseBlock(const vector<vector<bool>> &toErase, vector<string> &board) {
    int cnt = 0;
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            if (toErase[i][j] == true) {
                board[i][j] = '-';
                ++cnt;
            }
        }
    }
    return cnt;
}

void rearrangeBoard(vector<string> &board) {
    for (int i=M-1; i>=0; --i) { // 아랫줄에서부터 점점 위로 올라감
        for (int j=0; j<N; ++j) {
            if (board[i][j] == '-')
                continue;
            int ni = i + 1;
            while (ni<M && board[ni][j]=='-') // 블록을 떨어뜨릴 위치 찾기
                ++ni;
            --ni; // 놓여진 블록 "바로 위에" 떨어뜨릴 것이므로 감소
            if (ni != i) { // ni 초기화 후 즉시 --ni하면 원래 i의 위치이므로
                board[ni][j] = board[i][j]; // 블록 떨어뜨리기
                board[i][j] = '-';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    M = m;
    N = n;
    bool isErasable = false;
    
    do {
        vector<vector<bool>> toErase(m, vector<bool>(n, false));
        isErasable = false;
        
        // 지워야할 블록 표시
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (board[i][j] == '-')
                    continue;
                if (isSquare(i,j,board) == true) {
                    toErase[i][j] = true;
                    isErasable = true;
                }
            }
        }
        
        // 블록 지우기
        if (isErasable) {
            answer += numEraseBlock(toErase,board);
            // 지워진 자리 재정렬
            rearrangeBoard(board);
        }
    } while (isErasable);
    
    return answer;
}

// 미해결