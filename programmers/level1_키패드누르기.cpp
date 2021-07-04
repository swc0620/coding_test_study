#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10, rightHand = 12, leftDist = 0, rightDist = 0;
    for (int i = 0; i < numbers.size(); i++){
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            leftHand = numbers[i];      // 왼손 누르고 누른 위치로 이동시킴
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            rightHand = numbers[i];
        }
        else {
            if (numbers[i] == 0){   // 0을 11로 바꾸어주기
                numbers[i] = 11;
            }
            
            // 전원 2씩 차감
            int new_leftHand = leftHand - 2;
            int new_rightHand = rightHand - 2;
            int new_target = numbers[i] - 2;
            
            // 가장 가까운 3의 배수를 찾자. 그리고 가로거리도 계산하자 (3의 배수면 0, 아니면 1)
            int left_nearest = 0;
            int right_nearest = 0;
            int leftDist_horizontal = 0;
            int rightDist_horizontal = 0;
            
            if (new_leftHand % 3 == 0) {
                left_nearest = new_leftHand;
            }
            else if (new_leftHand % 3 == 1) {
                left_nearest = new_leftHand - 1;
                leftDist_horizontal = 1;
            }
            else {
                left_nearest = new_leftHand + 1;
                leftDist_horizontal = 1;
            }
            
            if (new_rightHand % 3 == 0) {
                right_nearest = new_rightHand;
            }
            else if (new_rightHand % 3 == 1) {
                right_nearest = new_rightHand - 1;
                rightDist_horizontal = 1;
            }
            else {
                right_nearest = new_rightHand + 1;
                rightDist_horizontal = 1;
            }
            
            // 세로거리 : nearest 친구들과 target 차이를 구한 뒤, 3으로 나눔
            int leftDist_vertical = abs(left_nearest - new_target) / 3;
            int rightDist_vertical = abs(right_nearest - new_target) / 3;
            
            // 총 거리 : 가로거리 + 세로거리
            int leftDist = leftDist_horizontal + leftDist_vertical;
            int rightDist = rightDist_horizontal + rightDist_vertical;
            
            if (leftDist == rightDist){
                if (hand == "left"){
                    answer += "L";
                    leftHand = numbers[i];
                }
                else {
                    answer += "R";
                    rightHand = numbers[i];
                }
            }
            else if (leftDist < rightDist){
                answer += "L";
                leftHand = numbers[i];
            }
            else {
                answer += "R";
                rightHand = numbers[i];
            }
        }
    }
    return answer;
}