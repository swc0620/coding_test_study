#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;//오름차순 정렬
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (true) {
        if (pq.size() == 1 || pq.top() >= K) {
            break;
        }
        int min_1 = pq.top();
        pq.pop();
        int min_2 = pq.top();
        pq.pop();
        int num = min_1 + min_2 * 2;
        pq.push(num);
    }

    if (pq.size() == 1 && pq.top() < K) {
        return -1;
    }
    else {
        return scoville.size() - pq.size();
    }

}