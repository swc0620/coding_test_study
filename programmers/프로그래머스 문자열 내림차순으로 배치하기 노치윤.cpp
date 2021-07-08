#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(char a, char b) {
    return a > b;
}
string solution(string s) {
    string answer = "";
    vector<char> vec;
    for (int i = 0; i < s.length(); i++) vec.push_back(s[i]);
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size(); i++) answer += vec[i];
    return answer;
}

/*
    sort(s.begin(),s.end(),cmp); // cmp 대신 greater<char>() 쓰면 내림차순 가능
    answer=s;
    또한 가능.
*/