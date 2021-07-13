#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 

vector<int> solution(vector<int> numbers) { 
    vector<int> answer; 
    for (int i=0;i<numbers.size();i++){ 
        for (int j=i+1;j<numbers.size();j++){ 
            answer.push_back(numbers[i]+numbers[j]); 
        } 
    } 
    sort(answer.begin(), answer.end()); 
    answer.erase(unique(answer.begin(), answer.end()), answer.end()); 
    
    return answer;
}

// 벡터 내 중복값 제거
// v.erase(unique(v.begin(), v.end()), v.end());