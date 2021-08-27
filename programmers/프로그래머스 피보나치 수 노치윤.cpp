#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*int fibo(int n, vector<int>& num){ //top-down
    if(num[n]==-1){
        num[n]=fibo(n-1,num)+fibo(n-2,num);
    }
    return num[n]%1234567;
}*/
int fibo(int n, vector<int>& num) { //bottom-up
    for (int i = 2; i <= n; i++) {
        num[i] = num[i - 1] + num[i - 2];
        if (num[i] > 1234567) num[i] %= 1234567;
    }
    return num[n];
}
int solution(int n) {
    int answer = 0;
    vector<int> num(n + 1, -1);
    num[0] = 0; num[1] = 1;
    answer = fibo(n, num);
    return answer;
}