// baekjoon 1874 스택수열

#include <iostream>
#include <stack>
#include <vector>

int main (){
    int n;
    std::vector<int> v;
    std::vector<char> d;
    std::stack<int> s;

    std::cin >> n;
    for (int i=0; i<n; i++){
        int k;
        std::cin >> k;
        v.push_back(k);
    }

    std::vector<int>::iterator it;
    it = v.begin();
    for (int i=1; i<n+1; i++){
        s.push(i);
        d.push_back('+');
        while(!s.empty()){
            if (*it != s.top()){
                break;
            }
            else{
                s.pop();
                d.push_back('-');
                it++;
            }
        }
    }

    if (s.empty()){
        for (int i=0; i<d.size(); i++){
            std::cout << d[i] << "\n";
        }
    }
    else{
        std::cout << "NO" << "\n";
    }
    return 0;
}