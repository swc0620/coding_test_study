#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<int> order;//skill_trees[i]안의 skill 원소 찾으면 그 skill 문자열의 원소 번째수 를 넣는 벡터
        order.push_back(0);//처음 벡터에 0을 넣어줌으로써 간략화 가능.
        for (int j = 0; j < skill_trees[i].length(); j++) {
            int check = 0;
            for (int k = 0; k < skill.length(); k++) {
                if (skill_trees[i][j] == skill[k]) {//skill문자열의 원소라면
                    if (order.back() != k) {//앞서 나온 스킬의 번째수가 k가 아니면 불가능한 스킬 트리.(자신은 k+1번째 원소이므로 k번째 원소가 선행이 되어야함)
                        check = 1;
                        break;
                    }
                    order.push_back(k + 1);
                }
            }
            if (check == 1) break;
            if (j == skill_trees[i].length() - 1) {//끝까지 다 검사한 경우.
                if (check == 0) {
                    answer++;
                }
            }
        }
    }
    return answer;
}