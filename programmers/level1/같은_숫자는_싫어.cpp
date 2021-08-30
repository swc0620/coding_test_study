#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer{ arr[0] }; // empty() 비교횟수 줄이기 위해 첫번째 원소 먼저 넣어줌
    
    for (int i=1; i<arr.size(); ++i) {
        if (arr[i] != answer.back()) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}