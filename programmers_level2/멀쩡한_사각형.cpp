using namespace std;

long long GCD(long long w, long long h) {
    long long x;
    while (h != 0) {
        x = w % h; // 한쪽으로 나눈 나머지 ex) 36 % 24
        w = h; // 나누는 수 ex) 24
        h = x; // 나머지 ex) 12 -> 0 이 되면 나눠떨어지는 최대공약수 발견
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long wll = (long long) w;
    long long hll = (long long) h;
    answer = wll * hll - (wll + hll) + GCD(wll,hll);
    return answer;
}

// 작은 직사각형의 가로는 가로 길이를 최대공약수로 나눈 몫
// 작은 직사각형에서 대각선이 지나가는 정사각형의 수는 (가로 + 세로 - 1)
// 즉 (전체 정사각형 개수) - (반복되는 작은 직사각형 수) * (작은 직사각형의 가로 + 세로 - 1)
// w*h - gcd * (w/gcd + h/gcd - 1) = w*h - (w+h) + gcd