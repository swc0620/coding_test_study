#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (int i=2; i*i<=n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    set<int> ans;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i=1; i<=numbers.length(); ++i) {
            int tmp = stoi(numbers.substr(0,i));
            if (isPrime(tmp))
                ans.insert(tmp); // set이므로 중복 삽입 X
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return ans.size();
}