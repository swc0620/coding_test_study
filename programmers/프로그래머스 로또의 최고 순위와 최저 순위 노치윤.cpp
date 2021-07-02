#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int same_num = 0;
    int zero_num = 0;
    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) {
            zero_num++;
            continue;
        }
        else {
            for (int j = 0; j < 6; j++) {
                if (lottos[i] == win_nums[j]) {
                    same_num++;
                    break;
                }
            }
        }
    }
    //최고 순위=0에는 당첨이 되는 숫자가 들어가는 경우
    //최저 순위=0에 당첨이 안되는 숫자가 들어가는 경우
    int max_same = same_num + zero_num;
    int min_same = same_num;
    if (max_same == 1 || max_same == 0) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - max_same);
    }

    if (min_same == 1 || min_same == 0) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - min_same);
    }

    return answer;
}