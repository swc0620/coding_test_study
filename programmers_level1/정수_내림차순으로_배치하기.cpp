#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string tmp = to_string(n);
    sort(tmp.begin(), tmp.end(), greater<char>());
    long long answer = stoll(tmp);
    return answer;
}