#include <string>
#include <set>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<int> x = { 0,0,1,-1 };//U-D-R-L 순
    vector<int> y = { 1,-1,0,0 };
    set<string> idx_UDRL; //방문한 idx+그 다음 idx가 insert됨.
    int cur_x = 0;
    int cur_y = 0;
    for (int i = 0; i < dirs.length(); i++) {
        string temp1 = to_string(cur_x) + to_string(cur_y);

        if (dirs[i] == 'U') {
            if (cur_x + x[0] <= 5 && cur_y + y[0] <= 5 && cur_x + x[0] >= -5 && cur_y + y[0] >= -5) {
                cur_x += x[0];
                cur_y += y[0];
            }
            else {
                continue;
            }
        }
        else if (dirs[i] == 'D') {
            if (cur_x + x[1] <= 5 && cur_y + y[1] <= 5 && cur_x + x[1] >= -5 && cur_y + y[1] >= -5) {
                cur_x += x[1];
                cur_y += y[1];
            }
            else {
                continue;
            }
        }
        else if (dirs[i] == 'R') {
            if (cur_x + x[2] <= 5 && cur_y + y[2] <= 5 && cur_x + x[2] >= -5 && cur_y + y[2] >= -5) {
                cur_x += x[2];
                cur_y += y[2];
            }
            else {
                continue;
            }
        }
        else if (dirs[i] == 'L') {
            if (cur_x + x[3] <= 5 && cur_y + y[3] <= 5 && cur_x + x[3] >= -5 && cur_y + y[3] >= -5) {
                cur_x += x[3];
                cur_y += y[3];
            }
            else {
                continue;
            }
        }

        string temp2 = to_string(cur_x) + to_string(cur_y);
        if (idx_UDRL.find(temp2 + temp1) == idx_UDRL.end() && idx_UDRL.find(temp1 + temp2) == idx_UDRL.end()) { //만일 0,0 -> 1,0 으로 갔다면 set안에 0010 과 1000 이 모두 없다면 insert.
            idx_UDRL.insert(temp1 + temp2);
        }

    }
    answer = idx_UDRL.size();
    return answer;
}