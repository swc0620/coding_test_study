#include <vector>

using namespace std;

int GCD(int a, int b) { // 유클리드 호제법?
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r; // b로 나누어 떨어졌는가
    }
    return a;
} // ex) 3,12 -> 12,3 -> 3,0

int LCM(int a, int b, int gcd) {
    return a * b / gcd; // 공식
}

vector<int> solution(int n, int m) {
    int gcd = GCD(n,m);
    int lcm = LCM(n,m,gcd);
    
    return { gcd, lcm };
}