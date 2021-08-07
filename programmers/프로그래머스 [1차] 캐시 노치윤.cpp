#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (int i = 0; i < cities.size(); i++) {//모두 소문자로바꾸기
        for (int j = 0; j < cities[i].size(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
    }

    list<string> cache;
    map<string, int> cache_map;//도시명이 있는지 빠르게 검사하기 위한 map
    if (cacheSize == 0) {
        return 5 * cities.size();
    }

    if (cache.size() < cacheSize) {
        cache.push_front(cities[0]);
        cache_map[cities[0]] = 1;
        answer += 5;
    }
    for (int i = 1; i < cities.size(); i++) {
        if (cache.size() < cacheSize) {
            if (cache_map.find(cities[i]) != cache_map.end()) {//cache hit 발생.
                for (list<string>::iterator iter = cache.begin(); iter != cache.end(); iter++) {
                    if (*iter == cities[i]) {
                        cache.erase(iter);//삭제
                        break;
                    }
                }
                answer += 1;
                cache.push_front(cities[i]);
            }
            else {//cache miss 발생
                cache.push_front(cities[i]);
                cache_map[cities[i]] = 1;
                answer += 5;
            }
        }
        else {
            if (cache_map.find(cities[i]) != cache_map.end()) {//cache hit 발생.
                for (list<string>::iterator iter = cache.begin(); iter != cache.end(); iter++) {
                    if (*iter == cities[i]) {
                        cache.erase(iter);
                        break;
                    }
                }
                answer += 1;
                cache.push_front(cities[i]);
            }
            else {//cache miss 발생
                string temp = cache.back();//맨 뒤 원소 삭제
                cache.pop_back();
                cache_map.erase(temp);

                cache.push_front(cities[i]);//맨 앞으로 insert
                cache_map[cities[i]] = 1;
                answer += 5;
            }
        }

    }

    return answer;
}