#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int days = 0;
    string week[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"}; // 나머지가 1일 때 금요일로 맞춰줌(1월 1일 금요일)
    int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (int i=0; i<a-1; i++){  // 5월이면, 4월까지 더해줌
        days += month[i];
    }
    days += b;  // 나머지 일수 더해줌
    
    answer = week[days % 7];
    return answer;
}