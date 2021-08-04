#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{ 0,0 };
    set<string> used;
    bool invalid, duplicate, one_lettered;
    
    for (int i=0; i<words.size(); ++i) {
        invalid = i > 0 && words[i].front() != words[i-1].back(); // 첫번째 단어일 경우 조건에서 빼줘야해서 세 개의 bool 변수로 조건 분리
        duplicate = i > 0 && used.find(words[i]) != used.end();
        one_lettered = words[i].length() == 1;
        
        if (invalid || duplicate || one_lettered) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
        
        used.insert(words[i]);
    }
    return answer;
}