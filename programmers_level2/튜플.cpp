#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compareSize(const vector<int> &a, const vector<int> &b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    set<int> contains; // 중복 제거
    vector<int> element; // tuple_set의 원소
    vector<vector<int>> tuple_set; // parsing
    string num{ "" };
    
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '{') 
            continue; // 빠른 처리
        
        if (isdigit(s[i])) {
            num += s[i];
        } else if (s[i] == ',') {
            if (s[i-1] == '}') // 이전 원소와 구분하는 쉼표
                continue;
            element.push_back(stoi(num));
            num.clear();
        } else { // '}'
            if (s[i-1] == '}')
                break; // 모든 원소 순회
            element.push_back(stoi(num));
            tuple_set.push_back(element);
            num.clear();
            element.clear();
        }
    }
    sort(tuple_set.begin(), tuple_set.end(), compareSize);
        
    for (vector<int> element : tuple_set) {
        for (int num : element) {
            if (contains.find(num) == contains.end()) { // 처음 만나는 원소
                contains.insert(num);
                answer.push_back(num);
            }
        }
    }
    
    return answer;
}