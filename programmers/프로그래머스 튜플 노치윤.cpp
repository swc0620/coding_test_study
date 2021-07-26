#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> brace_left;//{의 인덱스를 담을 벡터
    vector<int> brace_right;//}의 인덱스를 담을 벡터

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') brace_left.push_back(i);
        else if (s[i] == '}') brace_right.push_back(i);
    }

    vector<int> brace;//{ 와 } 사이 거리를 담을 벡터 - 가장 작은 것부터 차례로 그 사이의 숫자 개수가 적은거임.
    for (int i = 0; i < brace_left.size(); i++) {
        brace.push_back(brace_right[i] - brace_left[i]);
    }
    sort(brace.begin(), brace.end());

    for (int i = 0; i < brace.size(); i++) {//{ } 사이 숫자 갯수가 작은 것부터 차례로 answer에 넣으면 완성!

        //ex. {{2},{2,1},{2,1,3},{2,1,3,4}} 인경우 2부터 answer에 넣고, {2,1}에선 2가 이미 answer에 있으므로 1만 넣고, {2,1,3}에선 2,1이 이미 있으므로 3만 넣고~
        string temp = "";
        vector<int> repos;//,의 idx 저장.
        for (int j = 0; j < brace_left.size(); j++) {
            if (brace_right[j] - brace_left[j] == brace[i]) {
                temp = s.substr(brace_left[j] + 1, brace[i] - 1);//temp에는 {2,1,3}의 경우 2,1,3만 담김.
                break;
            }
        }
        if (i == 0) {//가장 작은 brace[0]의 temp에는 오직 숫자만 있기에 이를 바로 int형으로 변환해 answer에 푸시
            answer.push_back(stoi(temp));
            continue;
        }
        repos.push_back(-1);//49번째 줄을 수월하게 하기 위해 필요.
        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] == ',') {
                repos.push_back(k);
            }
        }

        for (int z = 0; z < repos.size(); z++) {
            string t = "";
            if (z == repos.size() - 1) {
                t += temp.substr(repos[z] + 1);
            }
            else t += temp.substr(repos[z] + 1, repos[z + 1] - repos[z] - 1);
            //t에는 숫자만 담김. ex) temp가 2,1,3 인경우 for 루프를 돌면서 2 1 3 이 차례로 t에 담김
            auto it = find(answer.begin(), answer.end(), stoi(t));
            if (it == answer.end()) {// 만일 t가 answer에 없다면 푸시
                answer.push_back(stoi(t));
                break;
            }
        }

    }

    return answer;
}