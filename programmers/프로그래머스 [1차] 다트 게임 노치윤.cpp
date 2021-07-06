#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score = { 0,0,0 };
    int cnt = 0;
    while (dartResult.length() != 0) {
        string temp = dartResult.substr(0, 2);
        int num;
        if (temp[1] == '0') {//10인 경우 처리(10S 의 경우 1 삭제후 num에 10 대입)
            dartResult.erase(0, 1);
            temp = dartResult.substr(0, 2);
            num = 10;
        }
        else {
            num = temp[0] - '0';
        }
        if (temp[1] == 'S') {
            score[cnt] = num;
        }
        else if (temp[1] == 'D') {
            score[cnt] = num * num;
        }
        else {
            score[cnt] = num * num * num;
        }
        if (dartResult[2] == '*') {
            if (cnt == 0) {
                score[cnt] *= 2;
            }
            else {
                score[cnt] *= 2;
                score[cnt - 1] *= 2;
            }
            dartResult.erase(0, 3);
            cnt++;
            continue;
        }
        else if (dartResult[2] == '#') {
            score[cnt] *= -1;
            dartResult.erase(0, 3);
            cnt++;
            continue;
        }
        cnt++;
        dartResult.erase(0, 2);
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}