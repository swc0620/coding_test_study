#include <string>
#include <vector>

using namespace std;

//유클리드 알고리즘

//최대 공약수
int gcd(int a, int b) {
    int c;
    int tmp;

    if (a<b){ //a에 큰 값을 위치시키기 위한 조건문
        tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

/* 최대 공약수 (재귀) -> swap 과정도 필요 없음
int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}
*/

//최소 공배수
int lcm(int a, int b, int c) {
    return a * b / c;
}
 
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m, answer[0]));
    return answer;
}
