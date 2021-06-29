// baekjoon 10828 스택

#include <iostream>
#include <stack>
#include <string>

int main (){
    int n;
    std::cin >> n;

    std::stack<int> st;
    std::string str;

    for (int i=0; i<n; i++){
        std::cin >> str;

        if (str == "push"){
            int num;
            std::cin >> num;
            st.push(num);
        }

        else if (str == "pop"){
            if (st.empty()){
                std::cout << "-1" << std::endl;
            }
            else{
                // top() : 상단의 값을 리턴하는 함수
                std::cout << st.top() << std::endl;
                st.pop();
            }
        }

        else if (str == "size"){
            std::cout << st.size() << std::endl;
        }

        else if (str == "empty"){
            if (st.empty()){
                std::cout << "1" << std::endl;
            }
            else{
                std::cout << "0" << std::endl;
            }
        }

        else if (str == "top"){
            if (st.empty()){
                std::cout << "-1" << std::endl;
            }
            else{
                std::cout << st.top() << std::endl;
            }
        }
    }
    return 0;
}