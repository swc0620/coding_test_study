#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int distance(int left, int right, int num) {
    if (num == 0) {
        num = 11;
    }
    //각 점의 좌표 부여, 1=(0,0), 2=(0,1), 3=(0,2)~~
    int right_x = (right - 1) / 3;
    int right_y = (right - 1) % 3;
    int left_x = (left - 1) / 3;
    int left_y = (left - 1) % 3;
    int num_x = (num - 1) / 3;
    int num_y = (num - 1) % 3;

    int right_dis = abs(num_x - right_x) + abs(num_y - right_y);
    int left_dis = abs(num_x - left_x) + abs(num_y - left_y);
    if (right_dis < left_dis) {
        return 2;
    }
    else if (right_dis > left_dis) {
        return 1;
    }
    else {
        return 0;
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 0) {
            numbers[i] = 11;
        }
        if (numbers[i] % 3 == 1) {
            left = numbers[i];
            answer += "L";
        }
        else if (numbers[i] % 3 == 0) {
            right = numbers[i];
            answer += "R";
        }
        else {
            int compare = distance(left, right, numbers[i]);
            if (compare == 1) {//왼손으로 가는게 가까움
                left = numbers[i];
                answer += "L";
            }
            else if (compare == 2) {
                right = numbers[i];
                answer += "R";
            }
            else {//거리 동일
                if (hand == "right") {
                    answer += "R";
                    right = numbers[i];
                }
                else {
                    answer += "L";
                    left = numbers[i];
                }
            }
        }

    }
    return answer;
}