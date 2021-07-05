#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> temp;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            temp.insert(numbers[i] + numbers[j]);
        }
    }
    for (set<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
        answer.push_back(*iter);
    }
    return answer;
}