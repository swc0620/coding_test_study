#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> total;
    int cnt = 0;
    //벡터를 1로 초기화 하고 체육복을 잃어버린 학생은 -1 여유분을 가진 학생은 +1을 해줌
    while (cnt < n) {
        total.push_back(1);
        cnt++;
    }
    for (int i = 0; i < lost.size(); i++) {
        total[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        total[reserve[i] - 1]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        if (total[lost[i] - 1] == 0) {
            if (lost[i] == 1) {
                if (total[lost[i]] == 2) {
                    total[lost[i]]--;
                    total[lost[i] - 1]++;
                }
            }
            else if (lost[i] == n) {
                if (total[lost[i] - 2] == 2) {
                    total[lost[i] - 2]--;
                    total[lost[i] - 1]++;
                }
            }
            else {
                if (total[lost[i] - 2] == 2) {
                    total[lost[i] - 2]--;
                    total[lost[i] - 1]++;
                    continue;
                }
                else if (total[lost[i]] == 2) {
                    total[lost[i]]--;
                    total[lost[i] - 1]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (total[i] != 0) {
            answer++;
        }
    }
    return answer;
}