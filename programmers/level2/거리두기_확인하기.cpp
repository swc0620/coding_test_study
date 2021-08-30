#include <string>
#include <vector>

using namespace std;

int dx[4] = { 0,0,-1,1 }; // 상하좌우
int dy[4] = { 1,-1,0,0 };

int check(const vector<string> &room) {
    for (int x=0; x<5; ++x) {
        for (int y=0; y<5; ++y) {
            if (room[x][y] == 'P') { // 응시자 확인
                for (int i=0; i<4; ++i) { // 응시자 상하좌우 (맨허튼 거리 1)
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx<0 || ny<0 || nx>=5 || ny>=5) // 경계
                        continue;
                    if (room[nx][ny] == 'X') // 파티션
                        continue;
                    if (room[nx][ny] == 'P') // 거리두기 X
                        return 0;
                    for (int j=0; j<4; ++j) { // 맨허튼 거리 2
                        int nnx = nx + dx[i];
                        int nny = ny + dy[i];
                        if (nnx==x && nny==y) // 자기자신 이미 확인
                            continue;
                        if (nnx<0 || nny<0 || nnx>=5 || nny>=5)
                            continue;
                        if (room[nnx][nny] == 'X')
                            continue;
                        if (room[nnx][nny] == 'P')
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto room : places) {
        answer.push_back(check(room));
    }
    return answer;
}
// 합계: 82.8 / 100.0