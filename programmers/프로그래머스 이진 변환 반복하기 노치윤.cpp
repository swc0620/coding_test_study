#include <string>
#include <vector>

using namespace std;
string makebinary(int a) { //처음에는 int 로 반환을 함. 하지만 숫자가 커짐에 따라 수를 표현 못해서 계속 error가 나옴. 그래서 string으로 반환.
    string temp = "";
    while (a != 0) {
        temp += to_string(a % 2);
        a = a / 2;
    }
    return temp;
}
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (s != "1") {
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') temp++;
        }
        answer[1] += temp;//0의 개수 더하기.
        s = (makebinary(s.length() - temp));//1의 개수로 이진수 만들어 s에 다시 저장.(사실 s를 뒤집어야 이진수지만 굳이 뒤집을 필욘 x)
        answer[0]++;

    }
    return answer;
}