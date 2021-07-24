#include <string>
#include <vector>
using namespace std;
bool isChar(char c) {
    if (c < 'a' || c>'z') return false;
    return true;
}

int solution(string str1, string str2) {
    int answer = 0;
    string new_str1 = "";
    string new_str2 = "";
    for (int i = 0; i < str1.length(); i++) {
        str1[i] = tolower(str1[i]);
        new_str1 += str1[i];
    }
    for (int i = 0; i < str2.length(); i++) {
        str2[i] = tolower(str2[i]);
        new_str2 += str2[i];
    }//모두 소문자화.
    vector<string> str1_vec;
    vector<string> str2_vec;
    for (int i = 0; i < new_str1.length() - 1; i++) {
        if (isChar(new_str1[i]) && isChar(new_str1[i + 1]))//자신과 자신 다음문자가 모두 소문자면
            str1_vec.push_back(new_str1.substr(i, 2));//추가
    }
    for (int i = 0; i < new_str2.length() - 1; i++) {
        if (isChar(new_str2[i]) && isChar(new_str2[i + 1])) 
            str2_vec.push_back(new_str2.substr(i, 2));
    }

    int intersect = 0;
    int uni = str1_vec.size() + str2_vec.size();
    for (int i = 0; i < str1_vec.size(); i++) {
        for (vector<string>::iterator iter = str2_vec.begin(); iter != str2_vec.end(); iter++) {
            if (str1_vec[i] == *iter) {
                intersect++;
                iter = str2_vec.erase(iter);
                break;
            }
        }
    }
    if (uni - intersect == 0) return 65536;
    answer = ((double)intersect / (uni - intersect)) * 65536;
    return answer;
}