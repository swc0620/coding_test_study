#include<vector>
#include <queue>
using namespace std;
 
int solution(vector<vector<int> > maps){
    
    int n = maps.size()-1;
    int m = maps[0].size()-1;
    
    int dx[] = {0,0 ,1 ,-1};
    int dy[] = {1,-1,0,0};
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty()){
        for(int i=0; i<4; i++){
            int nx = q.front().first + dx[i];
            int ny = q.front().second + dy[i];
 
            if(nx >= 0 && nx<= n && ny>= 0 && ny<= m && maps[nx][ny]==1){
                if(nx ==0 && ny ==0) continue;
                q.push({nx,ny});
                maps[nx][ny] = maps[q.front().first][q.front().second] +1;
            }
        }
        q.pop();
    }
    
    if (maps[n][m] == 1) return -1;
    else return maps[n][m];
}
