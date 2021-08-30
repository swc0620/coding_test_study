#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compareRate(pair<int,double> &a, pair<int,double> &b) { //비교 규칙 성립 필요
    if (a.second == b.second) { // 실패율 같으면
        return a.first < b.first; // 작은 번호의 스테이지 먼저
    }
    return a.second > b.second; // 실패율이 높은 스테이지 먼저
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> fail_rate;
    vector<int> accumulate_fail;
    accumulate_fail.resize(N+1);

    sort(stages.begin(), stages.end()); // 효율성을 위해 매 스테이지마다 stages.size()만큼 순회하는 대신 log(stages.size())로 정렬
    // [1,2,2,2,3,3,4,6]
    int i{ 0 }; // 정렬된 stages를 한 번만 순회할 수 있도록 index tracking
    for (int curr=1; curr<=N; ++curr) {
        pair<int,double> curr_stage{ curr,0 };
        while (stages[i] == curr) { // 현재 스테이지 실패자수 집계
            ++accumulate_fail[curr];
            ++curr_stage.second;
            ++i;
        }
        accumulate_fail[curr] += accumulate_fail[curr-1]; // 현재 스테이지 기준 누적 실패자수 집계 (도전자수 계산 위함)

        curr_stage.second = (curr_stage.second == 0) ? 0 : curr_stage.second / (stages.size() - accumulate_fail[curr-1]); // 실패율 = 현재 스테이지 실패자수 / 이전 스테이지에서 막힌 사용자를 뺀 전체 사용자수
        fail_rate.push_back(curr_stage);
    }

    sort(fail_rate.begin(), fail_rate.end(), compareRate); // logN만큼 걸림
    for (auto rate : fail_rate) {
        answer.push_back(rate.first);
    }
    return answer;
}

// 그런데 6ms 걸리는 테스트케이스도 있어서 효율성이 개선되지 않은 것 같기도 함