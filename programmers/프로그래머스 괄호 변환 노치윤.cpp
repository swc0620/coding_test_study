#include <string>
#include <vector>
using namespace std;
bool isCorrect(string p) {//올바른 괄호 문자열인가
    if (p.length() % 2 == 1) return false;
    vector<char> temp;
    for (int i = 0; i < p.length(); i++) {
        temp.push_back(p[i]);
    }
    vector<char> match;
    while (true) {
        if (temp.size() == 0) break;
        if (temp.back() == ')') {
            match.push_back(')');
            temp.pop_back();
        }
        else {
            if (match.size() == 0) return false;
            else {
                match.pop_back();
                temp.pop_back();
            }
        }
    }
    if (match.size() != 0) return false;
    return true;
}

string Recur(string p) {
    if (isCorrect(p)) return p;
    int left = 0;
    int right = 0;
    string u = "";
    string v = "";
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') left++;
        if (p[i] == ')') right++;
        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    string answer = "";
    if (isCorrect(u)) {
        u += Recur(v);
        answer = u;
    }
    else {
        answer += "(" + Recur(v) + ")";
        string u_temp = "";
        for (int j = 1; j < u.length() - 1; j++) {
            if (u[j] == '(') u_temp += ")";
            if (u[j] == ')') u_temp += "(";
        }
        answer += u_temp;
    }
    return answer;
}
string solution(string p) {
    string answer = "";
    answer = Recur(p);
    return answer;
}