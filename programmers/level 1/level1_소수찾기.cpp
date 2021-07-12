#include <string>
#include <vector>
#include <cmath>

using namespace std;
bool isPrime(int num){
    if (num == 1){
        return false;
    }
    else if (num == 2){
        return true;
    }
    else if (num % 2 == 0){
        return false;
    }
    else{
        for (int i=3; i<sqrt(num)+1; i+=2){
            if (num % i == 0){
                return false;
            }
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
