#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    map <string, string> uid_nick; // <uid, nickname>
    stringstream ss;
    string action;
    string id;
    string nickname;
    
    for (int i=0; i<record.size(); i++){
        ss.str(record[i]); // 공백을 기준으로
        ss >> action; // Enter, Leave, Change
        if (action == "Enter"){
            ss >> id;
            ss >> nickname;
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(id);
            uid_nick[id] = nickname;
        }
        else if (action == "Leave"){
            ss >> id;
            answer.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }
        else {
            ss >> id;
            ss >> nickname;
            uid_nick[id] = nickname;
        }
        ss.clear();
    }
    for (int i=0; i<answer.size(); i++){
        answer[i] = uid_nick[uid[i]] + answer[i]; // 아이디에 해당하는 닉네임
    }
    return answer;
}