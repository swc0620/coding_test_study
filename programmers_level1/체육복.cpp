#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size(); // 도난당하지 않은 학생
    
    // 여벌의 체육복이 있었지만 도난당한 학생 제거
    for (int i=0; i<reserve.size(); ++i) {
        for (int j=0; j<lost.size(); ++j) { // 전체 학생의 수가 30명 이하로 적으므로 이중for loop 사용해도 성능 저하 크지 않음
            if (reserve[i] == lost[j]) {
                ++answer;
                reserve[i] = lost[j] = -1; // 해당 학생은 여전히 한 개 체육복 남아있으므로 다른 학생이 빌려줄 필요 x
                break;
            }
        }
    }
    
    for (int need : lost) {
        for (int i=0; i<reserve.size(); ++i) {
            if (reserve[i]-1 == need || reserve[i]+1 == need) { // 이전의 학생이 여분 가지고 있는지 먼저 확인
                ++answer;
                reserve[i] = -1;
                break;
            }
        }
    }
    
    return answer;
}