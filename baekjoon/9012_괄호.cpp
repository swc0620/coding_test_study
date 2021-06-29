// baekjoon 9012 괄호

#include <iostream>
#include <stack>
#include <string>

bool check(std::string str){
    int len;
    len = (int)str.length();
    std::stack<int> st;

    for (int i=0; i<len; i++){
        char c = str[i];    // 문자열을 하나씩 받는다.

        if (c == '('){
            st.push(str[i]);
        }
        else{ 
            if (st.empty()){    // 닫는 괄호 시, 스택이 비어있으면 false
                return 0;
            }
            else{               // 닫는 괄호 시, 스택 안에 '('가 있으면 pop
                st.pop();
            }
        }
    }
    return st.empty();      // 반복문이 끝나고 스택에 괄호')'가 남아있으면 false
}

int main(){
    int n;
    std::cin >> n;

    for (int i=0; i<n; i++){
        std::string str;
        std::cin >> str;

        if (check(str)){
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}