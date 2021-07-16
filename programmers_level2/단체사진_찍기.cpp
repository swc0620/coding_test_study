#include <string>
#include <vector>
#include <algorithm> // next_permutation

using namespace std;

int absolute(int val) {
    return val >= 0 ? val : -val;
}

bool satisfies(int distance, char comparator, int val) {
    switch (comparator) {
        case '=':
            return distance == val;
        case '<':
            return distance < val;
        case '>':
            return distance > val;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do {
        bool flag = true;
        for (string condition : data) {
            int distance = absolute(friends.find(condition[0]) - friends.find(condition[2])) - 1; // 사람수를 세는 것이므로 1 차감
            char comparator = condition[3];
            int val = condition[4] - '0'; // char to int
            if (!satisfies(distance,comparator,val)) {
                flag = false;
                break; // 하나의 조건이라도 미충족 시 정지
            }
        }
        if (flag == true)
            ++answer;
        
    } while (next_permutation(friends.begin(), friends.end())); // 순열
    
    return answer;
}