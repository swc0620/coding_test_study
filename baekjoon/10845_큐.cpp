// baekjoon 10845 큐

#include <iostream>
#include <queue>
#include <string>

int main(){
    int N;
    std::cin >> N;

    std::queue<int> q;
    int num;

    for (int i=0; i<N; i++){
        std::string str;
        std::cin >> str;

        if (str == "push"){
            int data;
            std::cin >> data;
            q.push(data);
        }

        else if (str == "pop"){
            if (q.empty()){
                std::cout << "-1" << std::endl;
            }
            else{
                std::cout << q.front() << std::endl;
                q.pop();
            }
        }

        else if (str == "size"){
            std::cout << q.size() << std::endl;
        }

        else if (str == "empty"){
            if (q.empty()){
                std::cout << "1" << std::endl;
            }
            else{
                std::cout << "0" << std::endl;
            }
        }

        else if (str == "front"){
            if (q.size() == 0){
                std::cout << "-1" << std::endl;
            }
            else{
                std::cout << q.front() << std::endl;
            }
        }

        else if (str == "back"){
            if (q.size() == 0){
                std::cout << "-1" << std::endl;
            }
            else{
                std::cout << q.back() << std::endl;
            }
        }
    }
    return 0;
}