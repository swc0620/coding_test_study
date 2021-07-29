#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_truck = 0;
    int current_weight = 0;
    int finish = 0;
    queue<int> q;
    int cnt = 0;
    while (cnt < bridge_length) {
        q.push(0);
        cnt++;
    }//0이 칸 수라고 생각하자. ex) 다리길이가 4이면 4대의 차가 들어갈 수 있고 그 공간이 0.

    int idx = 0;
    while (true) {//예시 1 : 70 -> 07 -> 40 -> 54 -> 05 -> 60 -> 06 -> 00, 8초!
        int temp = q.front();
        if (temp != 0) {
            finish++;
            current_truck--;
            current_weight -= temp;
        }
        q.pop();
        if (finish == truck_weights.size()) {
            answer++;
            break;
        }
        if (current_weight + truck_weights[idx] <= weight) {
            q.push(truck_weights[idx]);
            current_truck++;
            current_weight += truck_weights[idx];
            idx++;
        }
        else {
            q.push(0);
        }
        answer++;

    }
    return answer;
}