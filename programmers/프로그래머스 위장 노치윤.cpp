#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> num;
    for (int i = 0; i < clothes.size(); i++) {
        if (num.find(clothes[i][1]) == num.end()) num[clothes[i][1]] = 1;
        else num[clothes[i][1]]++;
    }
    vector<int> cloth;
    for (auto iter = num.begin(); iter != num.end(); iter++) {
        cloth.push_back((*iter).second);
    }

    for (int i = 0; i < cloth.size(); i++) {
        answer *= (cloth[i] + 1);//의상 개수+안입은거
    }
    answer -= 1;//다 안입은거 제외
    return answer;
}