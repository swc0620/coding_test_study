#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> check;
vector<vector<int>> num;
void rotate(int x, int y, int n) {
    if (check[x + 1][y]) return;
    int cnt = num[x][y];
    check[x][y] = true;
    x++;
    while (x < n) {//왼쪽 아래로 내려가기
        if (check[x][y]) break;
        check[x][y] = true;
        num[x][y] = ++cnt;
        x++;
    }
    x--;//while문에서 마지막으로 더한 x빼주기
    y++;
    while (y < n) {
        if (check[x][y]) break;
        check[x][y] = true;
        num[x][y] = ++cnt;
        y++;
    }
    y--;//while문에서 마지막으로 더한 y빼주기
    x--;
    y--;
    while (x >= 0 && y >= 0) {
        if (check[x][y]) break;
        check[x][y] = true;
        num[x][y] = ++cnt;
        x--;
        y--;
    }
    x++;//while문에서 마지막으로 뺀 x더해주기
    y++;//while문에서 마지막으로 뺀 y더해주기
    rotate(x, y, n);
}

vector<int> solution(int n) {
    vector<int> answer;
    //1과 2는 위에서 걸러지지 않으므로 따로 체크.
    if (n == 1) {
        answer.push_back(1);
        return answer;
    }
    if (n == 2) {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
        return answer;
    }
    for (int i = 0; i < n; i++) {
        vector<bool> temp;
        vector<int> tmp;
        for (int j = 0; j <= i; j++) {
            temp.push_back(false);
            tmp.push_back(1);
        }
        check.push_back(temp);
        num.push_back(tmp);
    }
    rotate(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(num[i][j]);
        }

    }
    return answer;
}