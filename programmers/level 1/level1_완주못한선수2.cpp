// 해시: map으로 풀기

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> temp;
    
    for (string name: participant){
        temp[name]++;
    }
    
    for (string name: completion){
        temp[name]--;
    }
    
    for (auto pair: temp){
        if (pair.second > 0){
            return pair.first;
        }
    }
}