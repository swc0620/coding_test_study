#include <string>
#include <vector>
#include <cmath>
#define ASTERISK 10
#define HASH 12

using namespace std;

int distance(int from, int to) {
    int dist{ 0 };
    dist += abs((from-1) / 3 - (to-1) / 3); // 열
    dist += abs((from-1) % 3 - (to-1) % 3); // 행
    return dist;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_hand{ ASTERISK }, right_hand{ HASH };
    bool used_left{ false };

    for (int target : numbers) {
        if (target == 1 || target == 4 || target == 7) {
            used_left = true;
        } else if (target == 3 || target == 6 || target == 9) {
            used_left = false;
        } else {
            if (target == 0) target = 11;
            int dist_left{ distance(left_hand, target) }, dist_right{ distance(right_hand, target) };
            if (dist_left < dist_right) {
                used_left = true;
            } else if (dist_left > dist_right) {
                used_left = false;
            } else { // same distance
                if (hand == "left") {
                    used_left = true;
                } else {
                    used_left = false;
                }
            }
        }
        if (used_left) {
            left_hand = target;
            answer += 'L';
        } else {
            right_hand = target;
            answer += 'R';
        }
    }

    return answer;
}