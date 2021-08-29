#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b) {//a<b임. b와 a의 GCD는 a와 b%a의 GCD
    if (b % a == 0) return a;
    else {
        return GCD(b % a, a);
    }
}
int solution(vector<int> arr) {
    int answer = arr[0];
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++) {
        int gcd = GCD(answer, arr[i]);
        answer = answer * arr[i] / gcd;
    }
    return answer;
}