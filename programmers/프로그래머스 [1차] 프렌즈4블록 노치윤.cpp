#include <string>
#include <vector>
#include <set>
#include <utility>
#include <iostream>
using namespace std;

void move(vector<string>& board, set<pair<int, int>> index, int m, int n) {
    vector<int> cnt(n, 0);//세로줄마다 사라지는 원소 개수를 저장할 벡터.
    for (auto iter = index.begin(); iter != index.end(); iter++) {
        board[(*iter).first][(*iter).second] = '0';//규칙에 따라 사라지는 원소들을 0으로 바꿔줌.
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '0') {
                cnt[j] += 1;
            }
        }
    }

    vector<string> temp(n, "");//세로줄마다 사라지는 원소를 위로 올리고 나머지는 내려서 세로줄 string 을 새로 만드는 벡터. ex) 세로줄: "A00BC"->"00ABC"
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            temp[i] += '0';
        }
        for (int j = 0; j < m; j++) {
            if (board[j][i] != '0') {
                temp[i] += board[j][i];
            }
        }
    }


    vector<string> ans(m, "");//세로줄을 다시 가로줄로.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j] += temp[i][j];
        }
    }

    board = ans;//board 업데이트
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true) {
        set<pair<int, int>> index;//사라질 인덱스들을 저장하는 set.
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {//규칙에 따라 사라질 인덱스들 찾는 loop
                if (board[i][j] == board[i + 1][j] && board[i][j + 1] == board[i + 1][j + 1] && board[i][j] == board[i][j + 1] && board[i][j] != '0') {
                    index.insert(make_pair(i, j));
                    index.insert(make_pair(i + 1, j));
                    index.insert(make_pair(i + 1, j + 1));
                    index.insert(make_pair(i, j + 1));
                }
            }
        }
        answer += index.size();
        if (index.size() == 0) break;//하나도 사라지는 게 없다면 끝.
        move(board, index, m, n);//사라진 것들을 0으로 바꾸고 그 위의 원소들을 아래로 내려주는 함수
    }
    return answer;
}