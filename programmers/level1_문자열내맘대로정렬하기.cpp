#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int N;
bool compare(string a, string b){
    if(a[N] != b[N]){
        return a[N] < b[N];   //N인덱스의 문자로 정렬
    }
    else{
        return a < b;   //사전순으로 정렬
    }
}
 
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;
    N = n;
    sort(answer.begin(),answer.end(),compare);
    return answer;
}
