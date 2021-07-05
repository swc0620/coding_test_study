#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    //각 월에 해당하는 날짜 벡터
    vector<int> days = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int day = b - 1;//1일부터 시작
    for (int i = 0; i < a - 1; i++) {//그 날짜까지 모든 날짜 합
        day += days[i];
    }
    vector<string> vec = { "FRI","SAT","SUN","MON","TUE","WED","THU" };
    answer = vec[day % 7];
    return answer;
}