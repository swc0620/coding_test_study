#include <string>
#include <stack>

using namespace std;

bool isRight(const string &u) { // 올바른 괄호 문자열인지 판단
    if (u.empty())
        return true;
    
    stack<char> s;

    for (char c : u) {
        if (c == '(') {
            s.push(c);
        } else {
            if (s.empty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

string convert(const string &u) { // u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
    if (u.size() <= 2)
        return "";
    
    string result = "";
    for (int i=1; i<u.size()-1; ++i)
        result += (u[i] == '(' ? ')' : '(');
    
    return result;
}

string recur(string w) {
    if (w.empty())
        return w;
    
    int cnt = (w[0] == '(') ? 1 : -1;
    int off = 1; // 두번째 괄호부터
    while (cnt > 0)
        cnt += (w[off++] == '(' ? 1 : -1); // 개수 같으면 cnt == 0
    string u = w.substr(0,off); // 균형잡힌 괄호 문자열
    string v = w.substr(off);
    
    if (isRight(u))
        return u + recur(v);
    else
        return '(' + recur(v) + ')' + convert(u);
}

string solution(string p) {
    return recur(p);
}

// signal: aborted (core dumped)