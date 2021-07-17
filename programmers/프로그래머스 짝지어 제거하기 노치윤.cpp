#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<char> temp;
    temp.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (temp.size() == 0) {
            temp.push_back(s[i]);
        }
        else if (temp.back() == s[i]) {
            temp.pop_back();
        }
        else {
            temp.push_back(s[i]);
        }
    }
    if (temp.size() != 0) {
        answer = 0;
    }
    else {
        answer = 1;
    }
    return answer;
}

//substr은 새로운 메모리 공간을 할당하고 이 공간에 문자열을 옮겨야 하기에 효율성 측면에서 떨어질 수 밖에 없다!