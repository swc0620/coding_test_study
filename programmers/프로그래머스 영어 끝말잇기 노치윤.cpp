#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> game;
    int idx = -1;
    game.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (game.find(words[i]) != game.end()) {//같은게 있다면
            idx = i;
            break;
        }
        if (words[i - 1][words[i - 1].length() - 1] != words[i][0]) {//끝 알파벳이랑 시작 알파벳이랑 다른 경우
            idx = i;
            break;
        }
        game.insert(words[i]);
    }
    if (idx == -1) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(idx % n + 1);
        answer.push_back(idx / n + 1);
    }

    return answer;
}