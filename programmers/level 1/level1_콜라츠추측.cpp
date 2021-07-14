#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num; // num은 정수형의 범위를 가지지만, 반복의 결과로 홀수가 지속적으로 나오면 점점 그 범위를 넘어선다.

    while(1) {
        if(temp == 1) {
            break;
        }
        
        if(temp % 2 == 0) {
            temp = temp / 2;
        } else {
            temp = temp * 3 + 1;
        }     
        
        answer++;
        
        if(answer == 500) {
            return -1;
        }       
    }
    
    return answer;
}