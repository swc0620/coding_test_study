#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int temp;
    
    if (b<a){
        temp = a;
        a = b;
        b = temp;
    }
    
    for (int i=a; i<b+1; i++){
        answer += i;
    }
    return answer;
}