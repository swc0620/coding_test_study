#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> remaining;
    
    for (int i=0; i<progresses.size(); ++i) {
        int days = (int) ceil((100 - progresses[i]) / (double) speeds[i]);
        remaining.push(days);
    }
    
    while (!remaining.empty()) {
        int release = remaining.front();
        remaining.pop();
        int cnt = 1;
        while (!remaining.empty() && remaining.front() <= release) {
            ++cnt;
            remaining.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}