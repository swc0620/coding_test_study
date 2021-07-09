#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(string s) {
    bool answer = true;
    sort(s.begin(), s.end());
    if (s.length() == 4 || s.length() == 6) {
        if (s[s.length() - 1] > '9' || s[0] < '0') {
            //가장 ASCII코드가 큰 원소, 작은 원소가 숫자 범위를 벗어나면 숫자가 아닌 문자가 존재한다는 것.
            answer = false;
        }
        return answer;
    }
    return false;
}