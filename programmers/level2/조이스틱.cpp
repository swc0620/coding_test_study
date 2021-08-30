#include <string>

using namespace std;

// 조이스틱 상하 이동 총 횟수는 고정되어 있음. 어차피 AAA..로부터 name을 만들어야하기 때문에
// 관건은 좌우 이동 횟수를 최소화하는 것

int solution(string name) {
    int answer = 0;
    string initial(name.length(),'A');

    int cursor = 0;
    while (initial != name) {
        int left_step{ 0 }, right_step{ 0 }, min_step = name.length(), min_idx{ 0 };
        for (int i=0; i<name.length(); ++i) { // greedy 접근법
            if (initial[i] == name[i])
                continue; // 이미 만족시키므로 조이스틱 조작 불필요
            // 커서를 i 위치로 이동시킬지 확인
            if (cursor > i) {
                left_step = cursor - i;
                right_step = name.length() - cursor + i; 
            } else {
                left_step = cursor + name.length() - i;
                right_step = i - cursor;
            }

            if (left_step < min_step || right_step < min_step) {
                min_step = min(left_step, right_step);
                min_idx = i;
            }
        }
        cursor = min_idx;
        answer += min_step; // 좌우이동
        answer += min(name[cursor] - 'A', 'Z' - name[cursor] + 1); // 상하이동
        initial[cursor] = name[cursor]; // 알파벳 완성
    }

    return answer;
}