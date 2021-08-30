#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b) { 
    return a + b > b + a; // "3" + "30" > "30" + "3" 
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_to_string;
    for (int n : numbers)
         num_to_string.push_back(to_string(n));
    sort(num_to_string.begin(), num_to_string.end(), comp);
    
    if (num_to_string.front() == "0") {
        answer = "0";
    } else {
        for (string num : num_to_string)
            answer += num;
    }
    return answer;
}