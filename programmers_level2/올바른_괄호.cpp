#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stck;
    
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '(') {
            stck.push('(');
        } else {
            if (stck.empty())
                return false;
            stck.pop();
        }
    }

    return stck.empty();
}