using namespace std;

long long GCD(int w, int h) {
    for (int i = w; i > 0; i--) {
        if (w % i == 0 && h % i == 0) {
            return i;
        }
    }
}
long long solution(int w, int h) {
    long long answer = (long long)w * h;
    long long gcd = GCD(w, h);
    long long part = ((long long)w / gcd) + ((long long)h / gcd) - 1;
    //세로 개수 만큼 사각형이 겹치고 가로 개수-1 한 만큼 한 가로줄에 2개의 사각형이 동시에 대각선에 의해 잘리는 영역이 존재.(가로로 이동한다고 생각하자.)
    answer -= part * gcd;
    return answer;
}