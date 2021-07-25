#include <string>
#include <vector>
#include <cstring>

// DFS
using namespace std;

bool flag = false;
bool visited[5][5];
const int dy[]={-1,1,0,0};
const int dx[]={0,0,-1,1};

bool inRange(int y, int x) {
    return y>=0 && y<5 && x>=0 && x<5;
}

void dfs(int y, int x, vector<string>& board, int depth) {
    // base case (맨해튼 거리 2 이하 == 깊이 2를 초과하지 않는 선에서 탐색)
    if (flag==true || depth>2) return;

    // oops
    if (depth>0 && board[y][x]=='P') {
        flag=true;
        return;
    }

    visited[y][x]=true;

    for (int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!inRange(ny,nx) || visited[ny][nx] == true || board[ny][nx]=='X')
            continue;
        dfs(ny, nx, board, depth+1);
    }
}

bool solve(vector<string>& board) {
    vector<pair<int,int>> people;
    for (int i=0; i<board.size(); i++)
        for (int j=0; j<board[i].size();j ++)
            if (board[i][j]=='P'){
                people.push_back({i,j});
            }

    for (int i=0; i<people.size(); i++){
        flag = false;
        memset(visited,false,sizeof(visited));
        dfs(people[i].first, people[i].second, board, 0);
        if (flag == true) {
            return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place:places){
        if (solve(place)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}


/*

BFS

#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
bool BFS(int a, int b, vector<string> MAP)
{
    vector<vector<bool>> Visit(5, vector<bool>(5, false));
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(a, b), 0));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
 
        if (Cnt == 2) continue;
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
            {
                if (Visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == 'O')
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
 
                    }
                    else if (MAP[nx][ny] == 'P')
                    {
                        return false;
                    }
                }
                
            }
        }
    }
    return true;
}
 
int Find_Answer(vector<string> MAP)
{
    for (int i = 0; i < MAP.size(); i++)
    {
        for (int j = 0; j < MAP[i].size(); j++)
        {
            if (MAP[i][j] == 'P')
            {
                if (BFS(i, j, MAP) == false)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
 
vector<int> Function(vector<vector<string>> MAP)
{
    vector<int> Result;
    for (int i = 0; i < MAP.size(); i++)
    {
        Result.push_back(Find_Answer(MAP[i]));
    }
    return Result;
}
 
vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    answer = Function(places);
    return answer;
}
*/