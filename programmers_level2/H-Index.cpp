#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    int n = citations.size();
    for (int i=0; i<n; ++i) {
        if (citations[i] >= i+1)
            ++answer;
    }
    
    return answer;
}