#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
 
int visited[100][100];
int row, col;
int dx[4] = {0, 0, -1, 1}; // '상하좌우' 이동
int dy[4] = {1, -1, 0, 0}; // '상하좌우' 이동
 
int safe(int x, int y){
    if(x >= 0 && y >= 0 && x < row && y < col) return 1;
    else return 0;
}
 
int BFS(int x, int y, int color, vector<vector<int>> picture){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    int cnt = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int xpos = x+dx[i];
            int ypos = y+dy[i];
            
            if(safe(xpos, ypos) == 1 && picture[xpos][ypos] == color && visited[xpos][ypos] == 0){
                q.push({xpos, ypos});
                visited[xpos][ypos] = 1;
                cnt++;
            }
        }    
    }
    
    return cnt;
}
 
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요. 
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(visited, 0, sizeof(visited));    // visited 배열을 0으로 초기화
    row = m;
    col = n;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(picture[i][j] != 0 && visited[i][j] == 0){
                int temp = BFS(i, j, picture[i][j], picture);
                max_size_of_one_area = max(temp, max_size_of_one_area);
                number_of_area++;       // 'BFS 실행횟수'랑 같음
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(number_of_area);
    answer.push_back(max_size_of_one_area);
    
    return answer;
}