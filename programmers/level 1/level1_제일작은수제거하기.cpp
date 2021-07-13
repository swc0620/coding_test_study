#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = arr[0];
    int index = 0;
    
    if (arr.size() == 1){
        answer.push_back(-1);
        return answer;
    }
    
    for (int i=0; i<arr.size(); i++){
        answer.push_back(arr[i]);
    }
    
    for (int i=0; i<answer.size(); i++){
        if (answer[i] < min){
            min = answer[i];
            index = i;
        }
    }
    
    answer.erase(answer.begin() + index);
    
    return answer;
}