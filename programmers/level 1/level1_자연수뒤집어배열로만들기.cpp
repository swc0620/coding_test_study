#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int temp = 0;
    while (n > 0){
        temp = n % 10;
        answer.push_back(temp);
        n /= 10;
    }
    return answer;
}