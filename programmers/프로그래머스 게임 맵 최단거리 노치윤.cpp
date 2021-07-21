#include<vector>
#include <queue>
using namespace std;
struct Point {
    int x;
    int y;
    Point(int x_, int y_) {
        x = x_;
        y = y_;
    }
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    vector<vector<int>> check = maps;//들른 곳이면 0 아니면 1
    queue<Point> q;//BFS위해 queue 작성
    int x[4] = { 1,0,0,-1 };
    int y[4] = { 0,1,-1,0 };
    int y_size = maps[0].size();
    int x_size = maps.size();
    vector<vector<int>> dist(x_size, vector<int>(y_size));
    q.push(Point(0, 0));
    check[0][0] = 0;
    dist[0][0] = 1;

    while (q.size() != 0) {
        Point p = q.front();
        q.pop();
        int x_now = p.x;
        int y_now = p.y;
        for (int i = 0; i < 4; i++) {
            int x_next = x_now + x[i];
            int y_next = y_now + y[i];
            if (x_next < 0 || x_next >= x_size || y_next < 0 || y_next >= y_size) continue;//끝에 도달
            if (check[x_next][y_next] == 0) continue;//이미 방문한 곳
            q.push(Point(x_next, y_next));
            check[x_next][y_next] = 0;
            dist[x_next][y_next] = dist[x_now][y_now] + 1;
        }

    }
    if (dist[x_size - 1][y_size - 1] == 0) {
        return -1;
    }
    return dist[x_size - 1][y_size - 1];
}