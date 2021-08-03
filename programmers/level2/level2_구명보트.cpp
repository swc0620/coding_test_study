#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int solution(vector<int> people, int limit) {
    //(보트)나간횟수, 나간사람 수, 앞 인덱스
    int answer = 0, cnt = 0, begin = 0;
    int last_idx = people.size() - 1;
    sort(people.begin(), people.end()); // 오름차순

    while (true) {
        //제일 뒤에 무게를 넣기
        int last = people[last_idx];
        cnt++;    //한명 나감
        //최대제한에 제일무거운사람을 계산했을때 제일 가벼운사람이 탈수있다면
        if (limit - last >= people[begin])    {
            //앞사람 인덱스 증가와 보트에 탄사람 추가
            begin++;
            cnt++;
        }
        //보트 나간횟수 증가
        answer++;
        //보트를 타고 나간사람이 총인원보다 같거나 많아지면 반복문 종료
        if (cnt >= people.size()){
            break;
        }

        // 마지막 인덱스에서부터 한칸 앞으로
        last_idx--;
    }
    return answer;
}