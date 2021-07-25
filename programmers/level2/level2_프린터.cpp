#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq; 
    queue <pair<int, int>> q;
    for (int i=0; i<priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    while (!q.empty()){
        int index = q.front().first;
        int priority = q.front().second;
        q.pop();

        if (priority == pq.top()){  //현재 문서의 중요도가 가장 높은 중요도라면 인쇄
            pq.pop();
            answer += 1;
            if (index == location){ //현재 문서가 요청한 문서일 경우
                break;
            }
        }
        else{
            q.push(make_pair(index, priority));
        }
    }
    return answer;
}