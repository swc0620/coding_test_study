#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> tokenize(const string &action) {
    vector<string> tokens;
    stringstream ss(action);
    string token;
    
    while (getline(ss,token,' ')) {
        tokens.push_back(token);
    }
    
    return tokens;
}

// 한 유저는 서로 다른 닉네임을 동시에 두 개 가질 수 없다
// 나갔다가 닉네임 바꿔 다시 들어온 유저는 반드시 기존 로그에서 닉네임을 변경하게 되어 있다

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> users; // 유저 아이디, 닉네임
    vector<pair<string,int>> log; // 유저 아이디, 입장/퇴장
    int IN = 1;
    int OUT = 0;
    
    for (string action : record) {
        vector<string> tokens = tokenize(action);
        string userID = tokens[1];
    
        if (tokens[0] == "Enter") {
            if (users.find(userID) != users.end()) { // 채팅방에 등록된 ID
                users[userID] = tokens[2]; // 교체
            } else { // 새로 들어온 유저
                users.insert(make_pair(userID,tokens[2]));
            }
            log.push_back(make_pair(userID,IN));
        } else if (tokens[0] == "Leave") {
            log.push_back(make_pair(userID,OUT));
        } else {
            users[userID] = tokens[2];
        }
    }
    
    for (const auto &action : log) {
        string message = action.second == IN ? "님이 들어왔습니다." : "님이 나갔습니다.";
        answer.push_back(users[action.first] + message);
    }
    
    return answer;
}