#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    vector<long long> num;//expression 속 숫자들 저장하는 벡터
    vector<char> symbol;/expression 속 기호 저장하는 벡터
    int index = 0;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] > '9' || expression[i] < '0') {
            int number = stoi(expression.substr(index, i));
            num.push_back((long long)number);
            index = i + 1;
            symbol.push_back(expression[i]);
        }
    }
    int number = stoi(expression.substr(index));
    num.push_back((long long)number);

    long long answer = 0;
    vector<char> oper = { '*','+','-' };
    do {
        vector<long long> temp_n = num;
        vector<char> temp_s = symbol;
        for (int i = 0; i < 3; i++) {//모든 +, - * 계산시 한개의 숫자만 남게됨.(최종 연산 결과임)
            vector<long long> temp_num;
            vector<char> temp_oper;
            for (int j = 0; j < temp_s.size(); j++) {
                if (temp_s[j] == oper[i]) {//만일 우선순위에 해당하는 기호이면 먼저 다 계산하고 그 인덱스의 숫자는 푸시 안함.
                    if (oper[i] == '+') temp_n[j + 1] = temp_n[j] + temp_n[j + 1];
                    else if (oper[i] == '-') temp_n[j + 1] = temp_n[j] - temp_n[j + 1];
                    else if (oper[i] == '*') temp_n[j + 1] = temp_n[j] * temp_n[j + 1];
                }
                else {
                    temp_num.push_back(temp_n[j]);
                    temp_oper.push_back(temp_s[j]);
                }
            }
            temp_num.push_back(temp_n[temp_n.size() - 1]);
            temp_n = temp_num;
            temp_s = temp_oper;
        }
        //끝, 결과비교
        if (answer < abs(temp_n[0])) {
            answer = abs(temp_n[0]);
        }
    } while (next_permutation(oper.begin(), oper.end()));

    return answer;
}