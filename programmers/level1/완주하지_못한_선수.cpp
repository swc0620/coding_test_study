#include <string>
#include <vector>
//#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    /* 1st try: 정렬 후 비교 (맞은 것 확인)
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i=0; i<participant.size(); ++i) {
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }
    */
    
    // 문제 주제가 해시이므로 해시맵 사용
    unordered_map<string,int> completed_list; // unordered이 더 빠름
    for (string runner : completion) {
        ++completed_list[runner]; // 없으면 key, value=0 insert 후
    }
    
    for (string runner : participant) {
        --completed_list[runner];
        if (completed_list[runner] < 0) {
            return runner;
        }
    }

}