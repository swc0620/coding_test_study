#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> temp1;
    map<string, int> temp2;

    for (int i = 0; i < completion.size(); i++)
    {
        if (temp2.find(completion[i]) == temp2.end()) {
            temp2[completion[i]] = 1;
        }
        else {
            temp2[completion[i]]++;
        }
    }

    for (int i = 0; i < participant.size(); i++) {
        if (temp2.find(participant[i]) == temp2.end()) {
            return participant[i];
        }
        else {
            temp2[participant[i]]--;
            if (temp2[participant[i]] < 0) {
                return participant[i];
            }
        }
    }


}