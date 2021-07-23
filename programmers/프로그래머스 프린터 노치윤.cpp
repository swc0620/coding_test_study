#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    list<int> seque;
    vector<pair<int, int>> a;//value, idx 로 된 a vector
    for (int i = 0; i < priorities.size(); i++) {
        a.push_back(make_pair(priorities[i], i));
    }
    sort(priorities.begin(), priorities.end());
    vector<pair<int, int>>::iterator iter = a.begin();
    int turn = 1;
    while (true) {
        if (iter == a.end()) iter = a.begin();
        if ((*iter).first == priorities.back()) {//가장 큰 원소와 비교.
            if ((*iter).second == location) return turn;
            priorities.pop_back();
            iter = a.erase(iter);
            turn++;
        }
        else iter++;
    }
}