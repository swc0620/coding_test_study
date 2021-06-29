// 10816 숫자카드 2
// upper_bound, lower_bound 활용

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<int> vec;

    int N;
    std::cin >> N;
    for (int i=0; i<N; i++){
        int x;
        std::cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    int M;
    std::cin >> M;
    for (int i=0; i<M; i++){
        int num;
        std::cin >> num;
        auto l = upper_bound(vec.begin(), vec.end(), num); // 하한: 같거나 큰 거 중에서 첫번째 index
        auto r = lower_bound(vec.begin(), vec.end(), num); // 상한: 큰거 중에서 첫번째 index
        std::cout << l - r << ' ';      // 상한 - 하한 하면 총 같은 개수 나옴
    }
    std::cout << "\n";
    return 0;
}

/*
lower_bound : 이상(<=)
- 선형 구조의 부분탐색법
- 만약 target 값이 있다면, target 값보다 같거나 큰 첫번째 위치를 말한다.

upper_bound : 초과(<)
- target값보다 큰 첫번째 위치를 말한다.


ex) {1,2,3,3,4}란 배열에서
target은 3일 때,
Lower bound(이상) = 2 (index=위치)
Upper bound(초과) = 4 (index=위치)
*/