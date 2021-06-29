#include <iostream>
#include <deque>

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M; // 큐의 크기, 뽑아내려고 하는 수의 개수
    int idx = 0;
    int sum = 0;
    
    std::cin >> N >> M;
    std::deque<int> dq;

    int arr[50];
    for (int i=0; i<M; i++){
        int a;
        std::cin >> a;
        arr[i] = a;
    }

    for (int i=1; i<N+1; i++){
        dq.push_back(i);
    }

    while (idx < M){
        std::deque<int> temp;
        int left = 0;
        int right = 0;

        // 왼쪽으로 이동
        while (true){
            if (dq.front() == arr[idx]){
                break;
            }
            temp.push_back(dq.front());
            dq.pop_front();
            left++;
        }

        // 원복
        while (temp.size() != 0){
            dq.push_front(temp.back());
            temp.pop_back();
        }

        // 오른쪽
        while(true){
            if (temp.size() != 0 && temp.front() == arr[idx]){
                break;
            }
            int back = dq.back();
            dq.pop_back();
            right++;

            temp.push_front(back); // 맨 앞으로 온 값이 원하는 수인지 확인
        }

        while (temp.size() != 0){
            dq.push_back(temp.front());
            temp.pop_front();
        }

        if (left < right){
            sum += left;        // 왼쪽으로 밀기
            while (left--){
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            dq.pop_front();
        }
        else{
            sum += right;       // 오른쪽으로 밀기
            while (right--){
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
            dq.pop_front();
        }
        idx++;
    }
    std::cout << sum << "\n";
    return 0;
}