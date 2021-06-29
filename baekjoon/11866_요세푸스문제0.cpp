// baekjoon 11866 (1158 요세푸스문제랑 같은 코드)

#include <iostream>
#include <queue>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::queue<int> q;

    // 7 3
    for (int i=1; i<N+1; i++){
        q.push(i);
    }

    std::cout << "<";
    while (q.size()-1 > 0){
        for (int i=0; i<K-1; i++){ // 위에서 2개의 수를 제거하여 마지막에 다시 삽입
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << q.front() <<  ">";
    return 0;
}

// 출력: <3, 6, 2, 7, 5, 1, 4>