#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 0) {
        int remainder = n % 3;
        n /= 3;
        
        switch (remainder) {
            case 1:
                answer = to_string(1) + answer; 
                break;
            case 2:
                answer = to_string(2) + answer; 
                break;
            case 0:
                answer = to_string(4) + answer; 
                --n; // ex) 3 / 3 = 1 + 0 -> 1 % 3 = 0 + 1 => 14
                // 원래대로라면 3 / 3 = 1 + 0 -> 0 % 3 = 0 + 0 => 4
                break;
        }
    }
    return answer;
}