using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num; // 연산할 때 범위를 넘어감
    
    while (n != 1 && answer < 500) {
        if (n & 1) { // bitwise AND operator -> 1
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        ++answer;
    }
    
    if (answer > 500) answer = -1;
    return answer;
}