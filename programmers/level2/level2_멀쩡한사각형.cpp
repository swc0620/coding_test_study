using namespace std;

int gcd(int w, int h){
    int c;
    while (h != 0){
        c = w % h;
        w = h;
        h =c;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1;
    int gcd_ = 0;
    long long wasted = 0;
    
    gcd_ = gcd(w, h);
    wasted = w + h - gcd_;
    answer = ((long long) w * (long long) h) - wasted;
    
    return answer;
}