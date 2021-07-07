#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool isPrime(int num){
    for (int i=2; i<sqrt(num)+1; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    for (int i=1; i<n+1; i++){
        if (isPrime(i)){
            answer += 1;
        }
    }
   
    return answer;
}