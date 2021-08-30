#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1; // 자기 자신
    
    for (int i=1; i<=n/2; ++i) {
        int sum = i;
        
        for (int j=i+1; j<=n/2+1; ++j) {
            sum += j;
            
            if (sum >= n) {
                if (sum == n)
                    ++answer;
                break;
            }
        }
    }
    return answer;
}