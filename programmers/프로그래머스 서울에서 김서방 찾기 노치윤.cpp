#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int k = 0;

    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i].compare("Kim") == 0) {
            k = i;
        }
    }

    answer = "김서방은 " + to_string(k) + "에 있다";

    return answer;
}