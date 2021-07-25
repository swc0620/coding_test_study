#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
 
//합친 문자 비교해서 큰순으로 정렬하기
// ex ) 6, 10 이 있다면 610과 106하고 어떤게 큰지 비교
// 610이 더크므로 6, 10순으로 정렬하게 된다.
bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp; // 문자열로 변환된 numbers 벡터
    
    for (auto num : numbers)
        temp.push_back(to_string(num));
    
    sort(temp.begin(), temp.end(), cmp); // 맨 처음 수가 가장 큼
    
    if (temp[0] == "0"){ //처음 숫자가 0이라면 0을 반환
        return "0";
    }
    
    for (auto num : temp){ // 처음부터 끝까지 문자열 합치고 리턴
        answer += num;
    }
    
    return answer;
}