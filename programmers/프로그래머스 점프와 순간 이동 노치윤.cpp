#include <iostream>
using namespace std;


bool isPowerofTwo(int n) { //2¿« ∞≈µÏ¡¶∞ˆ¿Œ∞°
    while (n != 1) {
        if (n % 2 == 1) return false;
        else n = n / 2;
    }
    return true;
}
int solution(int n)
{
    int ans = 1;
    while (!isPowerofTwo(n)) {
        if (n % 2 == 1) {
            ans++;
            n = n - 1;
        }
        else {
            n = n / 2;
        }
    }

    return ans;
}