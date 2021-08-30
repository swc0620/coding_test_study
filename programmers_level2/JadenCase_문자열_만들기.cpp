#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool startWord = true;
    
    for (char c : s) {
        if (c == ' ') { // whitespace
            startWord = true; // end of previous word
        } else { // alphabet
            if (startWord) {
                c = toupper(c);
                startWord = false;
            } else {
                c = tolower(c);
            }
        }
        answer.push_back(c);
    }
    return answer;
}