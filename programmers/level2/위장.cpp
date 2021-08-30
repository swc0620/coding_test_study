#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m; // 의상의 종류 : 해당 종류의 의상 개수
    for (vector<string> info : clothes)
        m[info[1]] += 1; // 없으면 새로 키 생성
    
    
    for (auto element : m)
        answer *= element.second + 1; // 1개만 입는 경우, 다른 것들과 조합해서 입는 경우 포함
    
    return answer - 1; // 옷을 하나도 입지 않는 경우 제외
}