using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n > 0) {
        answer += n % 10; // 1의 자리에서부터
        n /= 10;
    }

    return answer;
}