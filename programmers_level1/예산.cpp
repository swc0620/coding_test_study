#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int sum{ 0 }, answer{ 0 };
    sort(d.begin(), d.end()); // 오름차순 정렬

    for (int money : d) {
        sum += money;
        if (sum > budget) { // 순서가 중요
            break;
        }
        ++answer;
    }
    return answer;
}