#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    string start = "";
    start.append(name.length(), 'A');
    vector<int> up_down;
    int min = 500;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] > 'N') {
            up_down.push_back(26 - (name[i] - 'A'));
        }
        else {
            up_down.push_back(name[i] - 'A');
        }
    }
    //벡터 up_down에는 각 문자별 커서를 움직여야 하는 횟수가 저장됨.
    for (int i = 0; i < name.length(); i++) {//커서를 i index까지 우로 이동하고 그 지점에서 다시 좌로 이동. 이를 반복하면서 최소 횟수를 찾음
        vector<int>::iterator iter = up_down.begin();
        iter = iter + i;//시작 위치 index=i;
        string temp = start;//temp="AAA~"
        int cnt = i;//처음에 커서를 오른쪽으로 i번 움직여야 하므로
        int idx = i;
        while (temp != name) {
            cnt += *iter;//그 위치에 위아래 커서를 움직여야 하는 횟수 더함.
            if (iter == up_down.begin()) {
                iter = up_down.end();
            }
            iter--;
            cnt++;//좌로 움직이는 커서
            temp[idx] = name[idx];
            if (idx == 0) {//index 0에서 왼쪽으로 가면 맨 마지막 인덱스해당
                idx = name.length() - 1;
            }
            else {
                idx--;
            }
        }
        if (cnt < min)min = cnt;
    }
    if (min == 0) return min;

    return min - 1;//마지막에는 커서를 움직이지 않아야 하는데 움직였으므로.
}