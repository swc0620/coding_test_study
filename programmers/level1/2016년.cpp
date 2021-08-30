#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string day[7]{ "FRI","SAT","SUN","MON","TUE","WED","THU"  }; // 1월 1일이 금요일
    int days_per_month[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 }; // 윤년이므로 2월은 29일

    int days_passed{ 0 };
    for (int i=0; i<a-1; ++i) {
        days_passed += days_per_month[i]; // 지나간 달들
    }
    days_passed += b-1; // 이번 달에서 지나간 날들

    string answer = day[days_passed % 7];
    return answer;
}