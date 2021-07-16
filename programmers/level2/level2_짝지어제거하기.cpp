#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    // 홀수는 무조건 하나 남음
    if(s.empty() || s.size() % 2 != 0)
        return answer;

    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }

    if(st.empty()) answer = 1;

    return answer;
}

/* 시간초과 -> 스택으로 풀기
int solution(string s)
{
    int answer = -1;
    int i = 0;
    while (true){
        if (i==s.size()) break;
        
        if (s[i] == s[i+1]){
            s.erase(i,2);
            i=0;    // 지우고 나서 다시 처음 인덱스부터 검색
        }
        else{
            i++;
        }
    }
    
    if (s.empty()) answer = 1;
    else answer = 0;
    
    return answer;
}
*/