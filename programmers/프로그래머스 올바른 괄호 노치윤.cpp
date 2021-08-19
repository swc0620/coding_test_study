#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> temp1;
    vector<char> temp2;
    for (int i = 0; i < s.length(); i++)
    {
        temp1.push_back(s[i]);
    }
    while (temp1.size() != 0) {
        if (temp1.back() == ')') {
            temp1.pop_back();
            temp2.push_back(')');
        }
        else {
            if (temp2.size() == 0) return false;
            else {
                temp1.pop_back();
                temp2.pop_back();
            }
        }
    }
    if (temp2.size() != 0) return false;
    return answer;
}