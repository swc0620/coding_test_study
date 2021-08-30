#include <vector>

using namespace std;

int GCD(int a, int b) { // Greatest Common Divisor : 유클리드 호제법 이용
    /* iterative
    int r;
    while (b > 0) {
        r = a % b; // a와 b의 최대공약수는 b와 r의 최대공약수와 같다 (증명 유)
        a = b;
        b = r;
    }
    return a;
    */
    
    // recursive
    if (b == 0)
        return a;
    return GCD(b, a % b);
    
    /* ex) a = 72, b = 30
    GCD(72, 30)
        GCD(30, 12)
            GCD(12, 6)
                GCD(6, 0)
                    return 6
    */    
}

int LCM(int a, int b) { // Least Common Multiple
    return a * b / GCD(a, b); // 최대공약수 * 최소공배수 = 두 수의 곱
}

int solution(vector<int> arr) {
    int n = arr[0];
    
    for (int i=1; i<arr.size(); ++i)
        n = LCM(n, arr[i]); // 두 수의 최소공배수 값과 다음 수의 최소공배수 구하기
    
    return n;
}