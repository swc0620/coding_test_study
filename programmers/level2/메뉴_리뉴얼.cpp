#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<int,int> best; // 코스 종류, 가장 많이 주문된 횟수
    map<string,int> combo; // 조합, 주문횟수
    
    for (int num : course) {
        best.insert(make_pair(num,0));
    }
    
    for (string order : orders) {
        do {
            for (int num : course) {
                string menu = order.substr(0,num);
                if (combo.find(menu) != combo.end()) { // 이미 존재하는 메뉴 조합인 경우 카운트 증가
                    ++combo[menu];
                } else {
                    combo.insert(make_pair(menu,1)); // 처음 나온 조합인 경우 map에 새로 추가
                }  
                if (best[num] < combo[menu])
                        best[num] = combo[menu]; // 해당 코스 종류의 최대 주문 횟수 update
            }
        } while (next_permutation(order.begin(),order.end())); // 오름차순으로 각 주문한 단품메뉴 조합에 대해 순열 생성
        
    }
    
    for (int num : course) {
        int best_cnt = best[num];
        for (auto itr=combo.begin(); itr!=combo.end(); ++itr) {
            if ((*itr).first.size() == num && (*itr).second == best_cnt)
                answer.push_back((*itr).first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}