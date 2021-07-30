#include <string>
#include <stack>

using namespace std;

bool isCorrect(string s) {
    stack<char> stck;
    for (char c : s) {
        if (c=='(' || c=='{' || c=='[') {
            stck.push(c);
        } else {
            if (stck.empty())
                return false;
            switch (stck.top()) {
                case '(': if (c==')') stck.pop();
                case '{': if (c=='}') stck.pop();
                case '[': if (c==']') stck.pop();
            }
        }
    }
    return stck.empty();
}

string rotate(string s) {
    string result = s.substr(1);
    result += s[0];
    return result;
}

int solution(string s) {
    int answer = 0;
    if (s.length() % 2 == 1)
        return answer;
    
    if (isCorrect(s))
        ++answer;
    for (int i=1; i<s.length(); ++i) {
        s = rotate(s);
        if (isCorrect(s))
            ++answer;
    }
    return answer;
}