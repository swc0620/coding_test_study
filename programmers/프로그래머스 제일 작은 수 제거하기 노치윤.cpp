#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
    }
    else {
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());//가장 작은 원소의 위치를 찾는 과정 14~21번째
        int num = arr[0];
        for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
            if (*iter == num) {
                temp.erase(iter);
                break;
            }
        }
        answer = temp;
    }
    return answer;
}

//14~21번째 줄을 min_element 함수(이터레이터 리턴)로 단순화 시킬수 있음
/*
arr.erase(min_element(arr.begin(), arr.end()));

min_element(arr.begin(), arr.end()) : 가장 작은 원소 위치에 이터레이터 리턴
erase: 주어진 이터레이터 위치의 값 삭제

*/