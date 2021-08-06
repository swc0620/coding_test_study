#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for (auto itr1=cities.begin(); itr1!=cities.end(); ++itr1) {
        transform(itr1->begin(), itr1->end(), itr1->begin(), ::tolower); // 대소문자 구분을 하지 않는다
        bool hit = false;
        
        for (auto itr2=cache.begin(); itr2!=cache.end(); ++itr2) {
            if (*itr1 == *itr2) { // 캐시에 이미 있음
                hit = true;
                answer += 1;
                cache.erase(itr2);
                cache.push_back(*itr1);
                break;
            }
        }
        
        if (!hit) {
            answer += 5;
            if (cacheSize != 0 && cache.size() == cacheSize)
                cache.erase(cache.begin());
            if (cache.size() < cacheSize)
                cache.push_back(*itr1);
        }
    }
    return answer;
}