#include <vector>

using namespace std;

int solution(int n) {
    int answer{ 0 };
    vector<int> ternary;

    int quotient{ n }, remainder{ 0 };
    while (quotient > 0) {
        remainder = quotient % 3;
        quotient /= 3;
        ternary.push_back(remainder); // 역순으로 반전된 값 저장
    }
    int mul{ 1 }; // for loop에서 multiple variable initialize하려면 복잡함
    for (int i=ternary.size()-1; i>=0; --i) { // 뒤의 자리에서부터 계산
        answer += ternary[i]*mul;
        mul *= 3;
    }

    return answer;
}