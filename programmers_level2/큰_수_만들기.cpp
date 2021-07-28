#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i=0,idx=-1; i<number.length()-k; ++i) {
        char max = '0';
        for (int j=idx+1; j<=k+i; ++j) {
            if (max < number[j]) {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }
    return answer;
}