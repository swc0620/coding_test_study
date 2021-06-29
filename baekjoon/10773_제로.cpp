// 10773 제로

#include <iostream>
#include <stack>

int main (){
    int K, N;
    int sum = 0;
    std::cin >> K;
    std::stack<int> st;

    for (int i=0; i<K; i++){
        std::cin >> N;
        if (N != 0){
            st.push(N);
        }
        else{
            st.pop();
        }
    }

    int size = st.size();
    for (int i=0; i<size; i++){
        sum += st.top();
        st.pop();
    }
    std::cout << sum << "\n";
    return 0;
}