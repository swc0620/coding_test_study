#include <string>
#include <vector>

using namespace std;

int sumDigits(int n) {
    int sum{ 0 };
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool solution(int x) {
    return x % sumDigits(x) == 0;
}