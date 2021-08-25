#include <string>
#include <iostream>
 
using namespace std;
 
int solution(int n) {
    //정답개수, 더하는 개수, 합
    int answer = 0, nums = 1, sum = 0;
    while (true) {
        sum = 0;
        //2개 조합부터 찾아보기
        for (int i = 1; i <= nums; i++)    sum += i;
        //sum이 n보다 커진다면 반복문 탈출
        if (sum > n)    break;
        //n-sum이 더하는 개수로 나누어진다면 카운트 증가
        if ((n - sum) % nums++ == 0)    answer++;
    }
    //자기자신만 더하는 방법이 있으므로 1개추가
    return answer;
}