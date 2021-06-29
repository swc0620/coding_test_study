// 11279 최대힙

#include <iostream>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    // less<int> : 내림차순
    std::priority_queue<int, std::vector<int>, std::less<int> > p_queue;
    
    int N;
    std::cin >> N;

    for (int i=0; i<N; i++){
        int temp;
        std::cin >> temp;

        if (temp == 0){
            if (p_queue.empty()){
                std::cout << "0" << "\n";
            }
            else{
                std::cout << p_queue.top() << "\n";
                p_queue.pop();
            }
        }
        else{
            p_queue.push(temp);
        }
    }
    return 0;
}