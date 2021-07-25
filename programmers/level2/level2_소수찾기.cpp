/* 순열을 이용
 * numbers의 모든 조합을 찾고 그중 소수인 것을 판별
 * set을 이용해 중복 제거
 */
 
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num == 1) return false;
    if(num == 2) return true;
    
    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    string s = numbers;
    sort(s.begin(), s.end(), greater<char>());
    vector<bool> prime(stoi(s) + 1);    // 기본값 0으로 초기화된 s+1길이의 벡터
    
    prime[0] = false;
    for(long long i=1; i<prime.size(); i++) {
        prime[i] = isPrime(i);
    }
    
    sort(numbers.begin(), numbers.end());
    set<int> ans;
    
    do{
        for(int i=1; i<=numbers.size(); i++) {
            string tmp = numbers.substr(0, i);
            if(prime[stoi(tmp)]) {
                ans.insert(stoi(tmp));
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return ans.size();;
}