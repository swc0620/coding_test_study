#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    stack<int> s; // s.top() == 현재 관찰 중인 주가의 index
    
    for (int i=0; i<size; ++i) {
        while (!s.empty() && prices[s.top()]>prices[i]) { // 주가 하락
            answer[s.top()] = i - s.top(); // 사이의 시간
            s.pop(); // 유지 기간 계산 종료
        }
        s.push(i);
    }
    
    // 스택에 남아있는 idx들이 가리키는 주가는 마지막 주식보다 같거나 낮은 가격, 즉 가격이 내려가지 않음
    while (!s.empty()) {
        answer[s.top()] = size - 1 - s.top(); // 끝까지
        s.pop();
    }
    return answer;
}