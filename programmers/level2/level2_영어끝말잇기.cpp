#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int num = 0, turn = 0; // 번호, 차례
    int sign = 0;
    
    // Note : 인덱스 i가 최종적인 답이 될 예정인데, i = 0이면 첫번째부터 틀렸다는 소리 --> 오류
    // 1번째 순서의 1번째 턴은 게임 규칙상 오류일 수 없음. 따라서 int i=1부터 시작
    for (int i=1; i<words.size(); i++){
        // (1) i-1번째 단어의 마지막 철자 == i번재 단어의 첫 철자
        if (words[i-1][words[i-1].size()-1] != words[i][0]) {
            sign = 1;
        }
        // (2) 단어 반복 체크 (i번째 기준으로 자기보다 "이전" 친구들을 쭉 서치한 뒤, 문제가 생기면 i를 범인으로 몰기
        for (int j=i-1; j>=0; j--) {
            if (words[i] == words[j]) {
                sign = 1;
            }
        }
        // 만약 sign이 발동되면, i번째가 문제라는 뜻이므로 num과 turn 결정 후 for문 탈출
        if (sign) {
            num = (i % n) + 1;
            turn = (i / n) + 1;
            break;
        }
    }
    answer.push_back(num);
    answer.push_back(turn);

    return answer;
}


/* 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int num = 0, turn = 0; // 번호, 차례
    int dup_idx = words.size(); // words의 인덱스보다 큰 값을 대입
    int sign = 0;
    
    // 반복되는 단어 체크
    for (int i=0; i<words.size()-1; i++){
        for (int j=i+1; j<words.size(); j++){
            if (words[i] == words[j]){
                dup_idx = j;
                num = (j % n) + 1;
                turn = (j / n) + 1;
                sign = 1;
                break;
            }
        }
        if (sign) break;
    }

    // 끝말잇기 첫 철자 잘못한 경우
    for (int i=0; i<words.size()-1; i++){
        if (words[i][words[i].size()-1] == words[i+1][0]) continue;
        else{
            if (i+1 < dup_idx){
                num = ((i+1) % n) + 1;
                turn = ((i+1) / n) + 1;
                break;
            }
        }
    }
    answer.push_back(num);
    answer.push_back(turn);

    return answer;
}
*/