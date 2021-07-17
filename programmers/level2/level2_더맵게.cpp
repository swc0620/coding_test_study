#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(vector<int> scoville, int K) {
    int answer = 0;
    int temp1;
    int temp2;
    // greater : minHeap
    // 기존 백터를 활용하여 priority_queue 만들기
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (true){
        // 가장 안 매운 음식이 K보다 크면 break
        if (pq.top() >= K){
            break;
        }
        
        temp1 = pq.top();
        pq.pop();
        temp2 = pq.top();
        pq.pop();
        pq.push(temp1 + temp2 * 2);
        answer += 1;
        
        // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1을 return
        if (pq.top() < K && answer==(scoville.size()-1)){
            return -1;
        }
    }
    
    return answer;
}