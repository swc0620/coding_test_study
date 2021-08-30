#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> moving;
    int sum = 0; // 다리를 건너고 있는 트럭의 무게 합
    int idx = 0; // idx번째 대기 트럭
    
    while (true) {
        ++answer;
        
        // 수용가능한 트럭 개수 한도 달성
        if (moving.size() == bridge_length) {
            sum -= moving.front(); // 다리 통과
            moving.pop();
        }
        
        int curr = truck_weights[idx]; // 다음 순번의 대기트럭
        
        // 다리가 다음 순번의 트럭 수용 가능
        if (sum + curr <= weight) {
            // 마지막 트럭이 다리를 건너게 됨
            if (idx == truck_weights.size() - 1) {
                answer += bridge_length; // 다리 길이만큼 시간이 걸리고 합계 계산 완료
                break;
            }
            moving.push(curr); // 새 트럭이 다리를 건너게 됨
            sum += curr;
            ++idx; // 그 다음 순번의 대기트럭
        } 
        // 다리가 다음 순번의 트럭 수용 불가
        else {
            moving.push(0); // 현재 올라가있는 트럭들에 이동시간 1초 추가 (다음 iteration)
        } 
    }
    return answer;
}