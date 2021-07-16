#include <vector>
#include <queue> // BFS

using namespace std;

vector<int> dx; // x좌표 거리
vector<int> dy;
bool visited[100][100];

int BFS(int a, int b, int m, int n, const vector<vector<int>> &picture) {
    int color = picture[a][b];
    int size = 1;
    queue<pair<int,int>> areaQ;
    areaQ.push(make_pair(a,b));
    visited[a][b] = true;
    
    while (!areaQ.empty()) {
        int x = areaQ.front().first;
        int y = areaQ.front().second;
        areaQ.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=0 && ny>=0 && nx<m && ny<n) { // 경계 안의 좌표
                if (picture[nx][ny]==color && visited[nx][ny]==false) {
                    visited[nx][ny] = true;
                    areaQ.push(make_pair(nx,ny)); // 같은 색의 영역이 늘어남
                    ++size;
                }
            }
        }
    }
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    dx = { 0,0,-1,1 }; // 상하좌우
    dy = { 1,-1,0,0 };  
    
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            visited[i][j] = false;
        }
    }
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (picture[i][j]!=0 && visited[i][j]==false) {
                int size = BFS(i,j,m,n,picture);
                if (size>max_size_of_one_area) {
                    max_size_of_one_area = size;
                }
                ++number_of_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}