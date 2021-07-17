#include <vector>

using namespace std;

void DFS(const vector<int> &numbers, const int &target, int &answer, int sum, int cnt) {
    if (cnt == numbers.size()){
        if (sum == target)
            ++answer;
        return; // 모든 숫자를 다 사용하고나면 반드시 return
    }
    DFS(numbers, target, answer, sum+numbers[cnt], cnt+1);
    DFS(numbers, target, answer, sum-numbers[cnt], cnt+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, answer, 0, 0);
    return answer;
}