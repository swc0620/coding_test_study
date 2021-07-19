#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> id_name;
    for (int i = 0; i < record.size(); i++) {//id의 최종 이름 저장 루프.
        if (record[i][0] == 'L') {
            continue;
        }
        string name = "";
        string id = "";
        string temp = "";
        for (int j = 0; j < record[i].length(); j++) {
            if (record[i][j] == ' ') {//첫번째 빈칸이 나오면
                temp = record[i].substr(j + 1);//temp에 저장. temp에는 "uid1234 Muzi" 이게 저장.
                break;
            }
        }

        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] == ' ') {
                id = temp.substr(0, k);
                name = temp.substr(k + 1);
                break;
            }
        }
        id_name[id] = name;
    }

    for (int i = 0; i < record.size(); i++) {
        string id = "";
        string temp = "";
        for (int j = 0; j < record[i].length(); j++) {
            if (record[i][j] == ' ') {
                if (record[i][0] == 'L') {//leave의 경우 바로 id를 구할 수 있음.
                    id = record[i].substr(j + 1);
                }
                temp = record[i].substr(j + 1);
                break;
            }
        }

        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] == ' ') {
                id = temp.substr(0, k);
                break;
            }
        }
        if (record[i][0] == 'E') {
            string input = id_name[id] + "님이 들어왔습니다.";
            answer.push_back(input);
        }
        else if (record[i][0] == 'L') {
            string input = id_name[id] + "님이 나갔습니다.";
            answer.push_back(input);
        }
        else {
            continue;
        }
    }

    return answer;
}