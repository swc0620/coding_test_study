#include<iostream>
#include<vector>
#include<deque>
 
#define endl "\n"
#define MAX 100
 
int N, K, L;
int MAP[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
std::vector<std::pair<int, char>> V;
 
void Print(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cout << MAP[i][j] << " ";
        }
        std::cout << endl;
    }
}
void Input(){
    std::cin >> N >> K;
    for (int i = 0; i < K; i++){
        int x, y;
        std::cin >> x >> y;
        x = x - 1;
        y = y - 1;
        MAP[x][y] = 1;    // 사과 = 1로 표시
    }
    std::cin >> L;
    for (int i = 0; i < L; i++){
        int a; 
        char b;
        std::cin >> a >> b;
        V.push_back(std::make_pair(a, b));
    }
}
 
int Turn_Direction(int d, char c){
    if (c == 'L'){
        if (d == 0) return 3;
        else if (d == 1) return 2;
        else if (d == 2) return 0;
        else if (d == 3) return 1;
    }
    else if (c == 'D'){
        if (d == 0) return 2;
        else if (d == 1) return 3;
        else if (d == 2) return 1;
        else if (d == 3) return 0;
    }
}
 
void Solution(){
    std::deque<std::pair<int, int>> Q;
    int x = 0;
    int y = 0;
    int d = 0;
    int Time = 0;
    int Idx = 0;
    Q.push_back(std::make_pair(x, y));
    MAP[x][y] = 2;
 
    while (1){
        Time++;
 
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if ((nx < 0 || ny < 0 || nx >= N || ny >= N) || MAP[nx][ny] == 2){
            break;
        }
        else if (MAP[nx][ny] == 0){
            MAP[nx][ny] = 2;
            MAP[Q.back().first][Q.back().second] = 0;
            Q.pop_back();
            Q.push_front(std::make_pair(nx, ny));
        }
        else if (MAP[nx][ny] == 1){
            MAP[nx][ny] = 2;
            Q.push_front(std::make_pair(nx, ny));
        }
        
 
        if (Idx < V.size()){
            if (Time == V[Idx].first){
                if (V[Idx].second == 'L'){
                    d = Turn_Direction(d, 'L');
                }
                else if(V[Idx].second == 'D') {
                    d = Turn_Direction(d, 'D');
                }
                Idx++;
            }
        }
        x = nx;
        y = ny;
    }
    std::cout << Time << endl;
}
 
void Solve(){
    Input();
    Solution();
}
 
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
 
    Solve();
 
    return 0;
}