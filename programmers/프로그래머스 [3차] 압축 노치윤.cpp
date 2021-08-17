#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> m;//검색에 용이하게 hashmap 사용
    char start = 'A';
    for (int i = 1; i <= 26; i++) {
        string temp = "";
        temp += start;
        m.insert(make_pair(temp, i));
        start++;
    }//A부터 Z까지
    int last_idx = 26;//hashmap 인서트 되어야하는 idx
    int cur_idx = 0;
    string w = "";
    while (cur_idx != msg.length()) {
        string temp = w;
        w += msg[cur_idx];
        if (m.find(w) != m.end()) {//찾음
            cur_idx++;
            if (cur_idx == msg.length()) {//마지막에는 hashmap에 저장되지 않고 나가기에 따로 지정
                answer.push_back(m[w]);
            }
        }
        else {
            last_idx++;
            m.insert(make_pair(w, last_idx));
            answer.push_back(m[temp]);//temp에는 hashmap에 있는 원소중 가장 긴 원소가 저장되어있음.
            w = "";
        }
    }
    return answer;
}