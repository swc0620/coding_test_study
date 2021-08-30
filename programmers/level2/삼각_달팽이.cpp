#include <vector>

using namespace std;

// 직각삼각형 모양으로 쌓았다고 생각

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n, vector<int>(n)); // 좌표식 접근 위해 초기화
    int x{ 0 }, y{ 0 }, num{ 1 };
    char direction{ 'd' }; // down
    
    for (int i=0; i<n; ++i) { // 방향이 전환되는 횟수
        switch (direction) {
            case 'd': // down
                for (int j=i; j<n; ++j)
                    snail[x++][y] = num++; // 아래 행, 같은 열; post-increment
                x--; // n-1번째 iteration에서 n으로 증가되었으므로 감소시켜주기
                y++; // 그 다음 채울 칸
                direction = 'r';
                break;
            case 'r': // right
                for (int j=i; j<n; ++j)
                    snail[x][y++] = num++;
                y--; // n으로 증가되었으므로 감소
                x--; y--; // 그 다음 채울 칸
                direction = 'u';
                break;
            case 'u': // up
                for (int j=i; j<n; ++j)
                    snail[x--][y--] = num++;
                x++; y++;
                x++; // 그 다음
                direction = 'd';
                break;
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<=i; ++j)
            answer.push_back(snail[i][j]);
    }
    
    return answer;
}