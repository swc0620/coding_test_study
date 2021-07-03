#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> count;
    //count[0]=>1이 나온 개수, count[1]=>2개 나온 개수~
    for (int i = 1; i <= N; i++) {
        count.push_back(0);
    }
    for (int i = 0; i < stages.size(); i++) {
        count[stages[i] - 1]++;//각 stage에 머무는 사람 count
    }
    double cnt = stages.size();
    vector<double> failure_rate;
    for (int i = 0; i < N; i++) {
        if (cnt == 0) {
            failure_rate.push_back(0);
            continue;
        }
        failure_rate.push_back(count[i] / cnt);
        cnt -= count[i];

    }

    vector<double> temp = failure_rate;
    //실패율이 오름차순으로 정리됨.
    sort(failure_rate.begin(), failure_rate.end());
    set<int> index;//answer에 넣은 인덱스를 하나씩 추가하는 set.
    //temp[i]: i+1번째 스테이지 실패율
    for (int i = failure_rate.size() - 1; i >= 0; i--) {
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == failure_rate[i]) {
                if (index.size() == 0 || index.find(j) == index.end()) {
                    answer.push_back(j + 1);
                    index.insert(j);
                    break;
                }
            }
        }
    }
    return answer;

}