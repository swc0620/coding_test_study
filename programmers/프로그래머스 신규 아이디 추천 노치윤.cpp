#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string new_id) {
    string answer = "";
    vector<char> vec;
    for (int i = 0; i < new_id.length(); i++) {
        vec.push_back(new_id[i]);
    }
    //step1
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = tolower(vec[i]);
    }

    //step2
    vector<char>::iterator iter = vec.begin();
    while (iter != vec.end()) {

        if ((*(iter) >= 'a' && *(iter) <= 'z') || (*(iter) >= '0' && *(iter) <= '9') || *(iter) == '-' || *(iter) == '_' || *(iter) == '.') {
            iter++;
        }
        else {
            iter = vec.erase(iter);
        }
    }
    //step3
    vector<char>::iterator iter_ = vec.begin();
    int check = 0;
    while (iter_ != vec.end()) {
        if (*(iter_) == '.') {
            if (check == 1) {
                iter_ = vec.erase(iter_);
            }
            else {
                check = 1;
                iter_++;
            }
        }
        else {
            check = 0;
            iter_++;
        }
    }
    //step4
    if (vec.size() != 0 && vec.front() == '.') {
        vec.erase(vec.begin());
    }
    if (vec.size() != 0 && vec.back() == '.') {
        vec.erase(--vec.end());
    }
    //step5
    if (vec.size() == 0) {
        vec.push_back('a');
    }
    //step6
    if (vec.size() > 15) {
        while (vec.size() > 15) {
            vec.pop_back();
        }
    }
    if (vec.back() == '.') {
        vec.erase(--vec.end());
    }
    //step7
    if (vec.size() <= 2) {
        char temp = vec.back();
        while (vec.size() <= 2) {
            vec.push_back(temp);
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        answer += vec[i];
    }
    return answer;
}