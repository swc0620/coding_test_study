#include <string>
#include <map>

using namespace std;

int solution(string s) {
    map<string,string> numeric{ {"zero","0"}, {"one","1"}, {"two","2"}, {"three","3"}, {"four","4"}, {"five","5"}, {"six","6"}, {"seven","7"}, {"eight","8"}, {"nine","9"} };
    string ans{ "" };
    string num{ "" };
    
    for (char c : s) {
        if (isdigit(c)) {
            ans += c;
        } else {
            num += c;
            auto itr = numeric.find(num);
            if (itr != numeric.end()) { // 대응되는 숫자가 있으면
                ans += itr->second;
                num = ""; // 초기화
            }
        }
    }
    return stoi(ans);
}