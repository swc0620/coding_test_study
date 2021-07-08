#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<string, int> bucket;
    for (int i = 0; i < strings.size(); i++) {
        string temp = "";
        temp += strings[i][n];
        temp += strings[i];
        //map의 key를 "n번째 문자 + 자기 자신 문자열" 로 하면 조건 5 만족하면서 정렬 가능
        bucket[temp] = i;
    }
    for (map<string, int>::iterator iter = bucket.begin(); iter != bucket.end(); iter++) {
        answer.push_back(strings[iter->second]);
    }
    return answer;
}