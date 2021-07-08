#include <string>
#include <cctype>
using namespace std;

bool solution(string s)
{
    int cnt_p{ 0 }, cnt_y{ 0 };

    for (char c : s) {
        c = tolower(c);
        if (c == 'p') ++cnt_p;
        else if (c == 'y') ++cnt_y;
    }

    return cnt_p == cnt_y;
}