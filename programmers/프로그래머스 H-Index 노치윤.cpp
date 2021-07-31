#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for (int i = citations.size(); i >= 1; i--) {
        if (citations[citations.size() - i] >= i) return i;//citations[citations.size() - i] >= i 인 경우 i 보다 큰 원소가 idx: citations.size() - i~citations.size()-1까지 i개 존재하게 됨.

    }
}