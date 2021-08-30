using namespace std;

int solution(int n)
{
    int ans = 0;
    
    // 최대한 순간이동 많이 하는 것이 이득
    // n, n/2, n/4... 하면서 순간이동하는데, 2로 나눈 값이 홀수이면 다시 2로 나누지 못하므로 점프 ("뒤로")
    
    while (n > 0) {
        if (n % 2 == 1)
            ++ans;
        n /= 2;
    }

    return ans;
}