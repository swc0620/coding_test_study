#include <deque>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> printer; // 위치, 중요도
    for (int i=0; i<priorities.size(); ++i) {
        printer.push_back(make_pair(i,priorities[i]));
    }
    
    int cnt = 0;
    
    while (!printer.empty()) {
        pair<int,int> front = printer.front();
        printer.pop_front(); // 1
        bool isPrior = true; // 가정
        for (auto itr=printer.begin(); itr!=printer.end(); ++itr) {
            if ((*itr).second > front.second) {
                printer.push_back(front); // 2
                isPrior = false;
                break;
            }
        }
        if (isPrior) {// 3
            ++cnt;
            if (front.first == location) { // 현재 인쇄하고 있는 문서가 내가 인쇄를 요청한 문서
                answer = cnt;
                break;
            }
        }       
    }
    return answer;
}