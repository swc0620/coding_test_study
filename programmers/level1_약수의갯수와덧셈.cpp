#include <string>
#include <vector>
#include <cmath>

using namespace std;

int find_division(int num){
    int count = 0;
    for (int i=1; i<num+1; i++){
        if (num % i == 0){
            count += 1;
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    int n = right - left + 1;
    for (int i=left; i<left+n; i++){
        if (find_division(i) % 2 == 0){
            answer += i;
        }
        else{
            answer -= i;
        }
    }
    return answer;
}