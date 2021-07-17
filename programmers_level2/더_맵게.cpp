#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int s : scoville)
        pq.push(s); // build heap
    
    while (pq.top() < K) {
        int mixed = pq.top(); // 가장 맵지 않은 음식의 스코빌 지수
        pq.pop();
        
        if (pq.empty()) { // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
            answer = -1;
            break;
        }
        
        mixed += pq.top() * 2; // 두 번째로 맵지 않은 음식의 스코빌 지수 * 2
        pq.pop();
        pq.push(mixed);
        ++answer;
    }
    
    return answer;
}