#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> vec;
    while (n != 0) {
        vec.push_back(n % 10);
        n /= 10;
    }
    sort(vec.rbegin(), vec.rend());//내림차순으로 정렬
    answer += vec[0];
    for (int i = 1; i < vec.size(); i++) {
        answer *= 10;
        answer += vec[i];
    }
    return answer;
}