#include <string>
#include <vector>

using namespace std;

int getBinaryCount1(int x) {
    int cnt{ 0 };
    while (x) {
        if (x % 2 == 1)
            ++cnt;
        x /= 2;
    }
    return cnt;
}
int solution(int n) {
    int answer = n;
    int target = getBinaryCount1(n), compare = 0;
    
    while (true) {
        compare = getBinaryCount1(++answer);
        if (compare == target) break;
    }
    
    return answer;
}