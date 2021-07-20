#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days;//걸리는 작업일수 계산
    for (int i = 0; i < progresses.size(); i++) {
        double a = (double)(100 - progresses[i]) / speeds[i];
        if (a != (int)a) days.push_back((int)a + 1);
        else days.push_back((int)a);
    }

    vector<int> cnt;
    int n = 0;
    int cmp = 1;
    while (true) {
        if (n >= days.size()) {
            break;
        }
        if (n + cmp < days.size() && days[n] >= days[n + cmp]) {//자신보다 작업일수가 적은 일이 뒤에 있을땐 cmp++
            cmp++;
        }
        else {//days[n] < days[n + cmp] 이면 cmp는 초기화. n도 n+cmp로 초기화
            n = n + cmp;
            cnt.push_back(cmp);
            cmp = 1;
        }
    }
    return cnt;
}