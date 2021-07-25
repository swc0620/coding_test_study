#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;
bool isPrime(int a) {
    if (a == 0 || a == 1)return false;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> vec;
    for (int i = 0; i < numbers.length(); i++) {//numbers 각 자리를 숫자로 분할.
        vec.push_back(numbers[i] - '0');
    }

    sort(vec.begin(), vec.end());
    set<int> b;
    do {//순열을 돌리면서 index[0], index[0:1]~~index[0:7]이 소수이면 set에 추가, 이를 모든 순열에 적용.
        int num = 0;
        for (int i = 0; i < numbers.length(); i++) {
            num += vec[i];
            if (isPrime(num)) b.insert(num);
            num *= 10;
        }
    } while (next_permutation(vec.begin(), vec.end()));
    answer = b.size();
    return answer;
}