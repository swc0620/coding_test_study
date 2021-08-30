#include <string>

using namespace std;

string solution(string s) {
    bool even{ true };
    
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == ' ') {
            even = true; // 0번째에서 다시 시작
            continue;
        }
        
        if (even) {
            s[i] = (char) toupper(s[i]);
            even = false;
        } else {
            s[i] = (char) tolower(s[i]);
            even = true;
        }
    }
    return s;
}