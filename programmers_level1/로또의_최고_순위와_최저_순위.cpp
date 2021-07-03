#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    int right{ 0 }, zero{ 0 };

    for (int num : lottos) {
        if (num == 0) ++zero;
        else {
            auto itr = find(win_nums.begin(), win_nums.end(), num);
            if (itr != win_nums.end()) ++right;
        }
    }

    vector<int> answer;
    answer.push_back(7 - (right + zero));
    answer.push_back(7 - right);

    for (int i=0; i<2; ++i) {
        if (answer[i] == 7) --answer[i];
    }
    return answer;
}