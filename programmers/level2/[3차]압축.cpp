#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dic;

    // 사전 초기화
    char letter = 'A';
    for (int i=1; i<27; ++i) {
        dic.emplace(string(1,letter),i); // char <-> string 변환 주의
        ++letter;
    }

    // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w 검색
    int new_idx = 27;
    string w = "";
    
    for (int idx=0; idx<msg.length();) {
        w += msg[idx];
        
        if (dic.find(w) == dic.end()) { // 맵에 없는 키
            // 입력에서 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록
            dic.emplace(w, new_idx++); // 먼저 해야 함
            w.pop_back(); // w에서 마지막 글자를 제거한 것이 사전에서 현재 입력과 일치하는 가장 긴 문자열
            answer.push_back(dic[w]);
            
            w = ""; // 새로운 검색키
        } else {
            idx++; // w에 msg[idx] 남아있도록
        }
    }
    
    answer.push_back(dic[w]);
        
    return answer;
}