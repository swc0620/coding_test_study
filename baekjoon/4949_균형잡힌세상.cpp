// 4949 균형 잡힌 세상

#include <iostream>
#include <string>
#include <stack>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while (true){
        std::string str;
        std::getline(std::cin, str);

        std::stack<char> st;
        bool ans = true;

        if (str.length() == 1 && str[0] == '.'){
            break;
        }
        
        for (int i=0; i<str.length(); i++){
            if (str[i] == '(' || str[i] == '['){
                st.push(str[i]);
            }
            else if (str[i] == ')'){
                if (st.empty() || st.top() == '['){
                    ans = false;
                }
                else{
                    st.pop(); // 스택 비우기
                }
            }
            else if (str[i] == ']'){
                if (st.empty() || st.top() == '('){
                    ans = false;
                }
                else{
                    st.pop();
                }
            }
        }

        if (st.empty() && ans){
            // 모든 과정이 끝났을 때, st이 비어있고, ans가 true -> 균형
            std::cout << "yes" << "\n";
        }
        else{
            std::cout << "no" << "\n";
        }
    }
    return 0;
}