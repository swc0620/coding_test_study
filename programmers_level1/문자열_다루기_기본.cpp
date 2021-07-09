#include <string>

using namespace std;

bool solution(string s) {
    bool answer = false;
    if (s.length() == 4 || s.length() == 6) {
        answer = true;
        for (char c : s) {
            if (!isdigit(c)) { // 따로 STL 불러올 필요 X
                answer = false;
                break;
            }
        }
    }
    return answer;
}