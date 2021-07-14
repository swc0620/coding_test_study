#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string s = to_string(x);
    int temp=0;
    for (int i=0; i<s.size(); i++){
        temp += s[i] - '0';
    }
    
    if (x % temp != 0){
        answer = false;
    }
    return answer;
}