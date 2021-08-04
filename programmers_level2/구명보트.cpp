#include <algorithm>
#include <vector>

using namespace std;

// 최대 탑승 인원이 2명이므로 최소값 + 최대값
int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int light = 0, heavy = people.size()-1;
    
    while (light <= heavy) {
        ++answer; // 보트 하나 준비
        if (people[light] + people[heavy] <= limit)
            ++light; // 제일 가벼운 사람 탑승
        --heavy; // 제일 무거운 사람 반드시 탑승
    }
    
    return answer;
}