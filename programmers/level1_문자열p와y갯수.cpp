#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    for (int i=0; i<s.size(); i++){
        s[i] = tolower(s[i]);
    }
    
    for (int i=0; i<s.size(); i++){
        if (s[i] == 'p'){
            p += 1;
        }
        else if (s[i] == 'y'){
            y += 1;
        }
    }
    
    if (p == y || (p == 0 && y == 0)){
        return true;
    }
    else{
        return false;
    }

    return answer;
}