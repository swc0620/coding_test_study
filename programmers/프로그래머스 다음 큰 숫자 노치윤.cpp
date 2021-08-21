#include <string>
#include <vector>
using namespace std;

string make_bi(int num) {
    string ans = "";
    while (num != 0) {
        ans = to_string(num % 2) + ans;
        num /= 2;
    }
    return ans;
}
int solution(int n) {
    int answer = 0;
    string num = make_bi(n);
    int cnt = num.length() - 1;
    bool find = false;//뒤에서 한칸씩 가다가 1을 만나면 true로 바뀜
    int zero_finish = cnt;
    while (cnt >= 0) {
        if (!find && num[cnt] == '0') {
            cnt--;
            continue;
        }
        if (find && num[cnt] == '0') break;
        if (num[cnt] == '1') {
            if (!find) zero_finish = cnt + 1;//처음으로 1이 나오면 0이 끝나는 인덱스를 저장.
            find = true;
        }
        cnt--;
    }//111~~~0'0(cnt)'111'0(zero_finish)'0
    int zero = num.length() - zero_finish;//뒤에서 1이 연속으로 나오는 지점까지 0의 개수
    int one = zero_finish - cnt - 1;//뒤에서 1이 연속으로 나오는 지점까지 1의 개수, ex) 1110000111100 -> zero=2, one=4

    string revised_num = "";
    if (cnt < 0) {//111110인 경우 1011110 으로, 1이 연속으로 나오는 지점이 맨 처음 인덱스 까지 지속될 경우 cnt = -1 이다.
        string temp1(zero, '0');
        string temp2(one - 1, '1');
        revised_num = "10" + temp1 + temp2;
    }
    else {
        string temp = num.substr(0, cnt);
        string temp1(zero, '0');
        string temp2(one - 1, '1');
        revised_num = temp + "10" + temp1 + temp2;//원래 숫자는 temp+01+temp2+temp1 이였음. 이를 temp+10+temp1+temp2로 바꾸면 최소
    }
    int two = 1;
    for (int i = revised_num.length() - 1; i >= 0; i--) {//다시 10진수로
        answer += (revised_num[i] - '0') * two;
        two *= 2;
    }
    return answer;
}