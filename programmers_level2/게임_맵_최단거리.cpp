#include<vector>
#include<queue>
using namespace std;

int MAX = 100001; // 101 * 101
int dist[101][101];
int bx[] = { 0,0,-1,1 }; // 상하좌우
int by[] = { 1,-1,0,0 };

int solution(vector<vector<int> > maps) {
    
    dist[0][0] = 0;
    int N = maps.size(); // 행
    int M = maps[0].size(); // 열
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            dist[i][j] = MAX;
        }
    }
    queue<pair<int,int>> q; // 좌표
    q.push(make_pair(0,0));    
    int answer = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; ++i) {
            int ax = x + bx[i];
            int ay = y + by[i];
            
            if (ax<0 || ay<0 || ax>=N || ay>=M) continue;
            if (maps[ax][ay] == 0) continue;
            if (dist[ax][ay] > dist[x][y]+1) { // relaxation
                dist[ax][ay] = dist[x][y]+1;
                q.push(make_pair(ax,ay));
            }
        }
    }
    answer = (dist[N-1][M-1] == MAX) ? -1 : dist[N-1][M-1] + 1;
    return answer;
}