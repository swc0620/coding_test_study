// 2164 카드2

#include <iostream>
#include <deque> 

int main(){
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int N;
        std::cin >> N;

        std::deque<int> dq;

        for (int i = 1; i < N+1; i++){
            dq.push_back(i);
        }

        while (dq.size()-1 > 0){
            dq.pop_front();             // 맨 위에 카드 버리기
            dq.push_back(dq.front());   // (윗줄에서 버린 카드의 다음 카드) 맨 위위 카드를 맨 아래로 옮김 --> 맨 앞에의 카드는 그대로 남겨짐
            dq.pop_front();
        }

        std::cout << dq.front() << "\n";
        return 0;
}