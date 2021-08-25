#include <string>
#include <climits>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer;
    
    int min = INT_MAX, max = INT_MIN;
    
    istringstream ss(s); // for input
    string num;
    
    while (getline(ss, num, ' ')) {
        int n = stoi(num);
        min = n < min ? n : min;
        max = max < n ? n : max;
    }
    
    answer = to_string(min) + " " + to_string(max);
    return answer;
}