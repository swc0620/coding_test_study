#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int idx = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    answer.append(to_string(idx));
    answer.append("에 있다");
    return answer;
}