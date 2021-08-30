#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> map;
    for (int i=0; i<skill.length(); ++i) {
        map.insert(make_pair(skill[i],i+1));
    }
    
    
    for (string tree : skill_trees) {
        int can_learn = 1; // map에서 첫번째 스킬만 배울 수 있는 상태
        bool isValid = true;
        
        for (char s : tree) {
            if (map[s] > can_learn) { // 내가 배울 수 있는 스킬이 아님
                isValid = false;
                break;
            } else if (map[s] == can_learn) { // 이제 다음 번째 스킬로 넘어갈 수 있음
                ++can_learn;
            }
        }
        
        if (isValid)
            ++answer;        
    }
    return answer;
}