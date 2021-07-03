#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    //예산이 작은 부서부터 주면 최대한 많이 줄 수 있다.
    sort(d.begin(), d.end());
    int money = 0;
    for (int i = 0; i < d.size(); i++) {
        money += d[i];
        if (money > budget) {
            break;
        }
        else {
            answer++;
        }
    }
    return answer;
}