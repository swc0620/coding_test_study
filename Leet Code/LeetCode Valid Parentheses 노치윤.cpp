#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> origin;
        vector<char> temp;
        for (int i = 0; i < s.length(); i++) {
            origin.push_back(s[i]);
        }

        for (int i = 0; i < s.length(); i++) {
            if (origin.back() == ')' || origin.back() == ']' || origin.back() == '}') {
                temp.push_back(origin.back());
                origin.pop_back();
            }
            else {
                if (origin.back() == '(') {
                    if (temp.size() != 0 && temp.back() == ')') {
                        temp.pop_back();
                        origin.pop_back();
                    }
                    else {
                        return false;
                    }
                }
                else if (origin.back() == '{') {
                    if (temp.size() != 0 && temp.back() == '}') {
                        temp.pop_back();
                        origin.pop_back();
                    }
                    else {
                        return false;
                    }
                }
                else if (origin.back() == '[') {
                    if (temp.size() != 0 && temp.back() == ']') {
                        temp.pop_back();
                        origin.pop_back();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if (temp.size() != 0) {
            return false;
        }
        return true;
    }
};