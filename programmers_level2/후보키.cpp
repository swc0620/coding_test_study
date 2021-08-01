#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isMinimal(const vector<int> &keys, const int &bit) {
    // 현재 속성 집합 bit가 기존에 만들어놓은 후보키 포함하면 최소성 위배
    for (int i=0; i<keys.size(); ++i) {
        if ((keys[i] & bit) == keys[i])
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int m = relation.size();
    int n = relation[0].size();
    vector<int> keys; // 후보키 담음
    
    /* 비트마스킹으로 표현한 가능한 모든 조합
    0001             학년
    0010         전공
    0011         전공 학년
    0100     이름
    0101     이름     학년
    0110     이름 전공
    0111     이름 전공 학년
    1000 학번
    1001 학번         학년
    1010 학번     전공
    1011 학번     전공 학년
    1100 학번 이름     
    1101 학번 이름     학년
    1110 학번 이름 전공 
    1111 학번 이름 전공 학년
    */
    // 후보키 속성 구성을 비트마스크 순열로 조합하여 집합에 넣을 것임
    for (int bit=1; bit<(1<<n); ++bit) {
        // 최소성
        if (!isMinimal(keys,bit))
            continue;
        
        set<vector<string>> s;
        for (int i=0; i<m; ++i) { // 각 행 튜플에서 키 조합 생성
            vector<string> val;
            for (int j=0; j<n; ++j) {
                if (bit & (1<<j)) // 비트마스크로 선택한 열과 현재 행에서 선택한 열 구성이 일치
                    val.push_back(relation[i][j]); // 현재 행에서 비트마스크 조합을 만족하는 속성값 추가
            }
            s.insert(val);
        }
        
        // set을 사용했으므로, 비트에 해당하는 속성값 조합에 중복이 발생했으면 insert해도 set 크기가 늘어나지 않는다
        // 유일성
        if (s.size() == m)
            keys.push_back(bit);
    }
    return keys.size();
}