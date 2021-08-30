#include <string>
#include <vector>

using namespace std;

char c[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string nthNum(int n, int x) { // 진법 n, 숫자 x
    string num{ "" };
    if (x == 0)
        return "0";
    
    while (x > 0) {
        num = c[x % n] + num;
        x /= n;
    }
    
    return num;
}
string solution(int n, int t, int m, int p) {
    string sequence{ "" }, answer{ "" };
    
    for (int i=0; i<t*m; ++i) // m명의 사람이 돌아가면서 말하므로
        sequence += nthNum(n, i);
    
    int turn = p - 1; // zero index
    for (int j=0; j<t; ++j) {
        answer += sequence[turn];
        turn += m;
    }
    
    return answer;
}