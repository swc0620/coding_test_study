#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    vector<int> second;
    vector<int> value;
    for (int i = 0; i < prices.size(); i++) {

        while (second.size() != 0 && value.back() > prices[i]) {
            value.pop_back();
            int sec = second.back();
            answer[sec] = i - sec;//i번째 인덱스일때 가격이 떨어졌으므로 i-sec 간 가격이 안떨어진것.
            second.pop_back();
        }
        second.push_back(i);
        value.push_back(prices[i]);
    }

    while (second.size() != 0) {//second 스택에 남은 값 처리.
        int sec = second.back();
        answer[sec] = prices.size() - 1 - sec;
        second.pop_back();
    }
    return answer;
}