#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sums;
    
    for (int i=0; i<numbers.size(); ++i) {
        for (int j=i+1; j<numbers.size(); ++j) {
            sums.insert(numbers[i]+numbers[j]); // 중복되는 값 들어가지 X
        }
    }
    
    vector<int> answer(sums.begin(), sums.end()); // set to vector
    return answer;
}