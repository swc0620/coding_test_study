#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> same;
    for (char c : s) {
        if (!same.empty() && same.top() == c)
            same.pop(); // 같은 문자 제거
        else
            same.push(c);
    }

    return same.empty() ? 1 : 0;
}