#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visit[11][11][11][11] = { false }; // [currX][currY][nextX][nextY] 현재 간선 - 다음 간선
    int currX{ 5 }, currY{ 5 }; // 시작 지점 (0,0) -> (5,5)
    
    for (char dir : dirs) {
        int nextX = currX, nextY = currY;
        switch (dir) {
            case 'U': nextX--; break; // 배열 개념이므로 index 감소시켜줘야 그 이전 행이 나옴
            case 'D': nextX++; break;
            case 'R': nextY++; break;
            case 'L': nextY--; break;
        }
        if (nextX < 0 || nextX > 10 || nextY < 0 || nextY > 10) continue; // 좌표평면의 경계를 넘어가는 명령어는 무시
        
        if (!visit[currX][currY][nextX][nextY]) {
            visit[currX][currY][nextX][nextY] = true;
            visit[nextX][nextY][currX][currY] = true;
            ++answer;
        }
        currX = nextX, currY = nextY; // 길 이동
    }
    return answer;
}