#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<int> d, int budget){
    int answer = 0;
 
    sort(d.begin(), d.end());
    // 1 2 3 4 5
    int i = 0;
    while (budget > 0){
        if (budget - d[i] < 0){
            break;
        }
        else{
            budget -= d[i];
            answer++;
        }
        i++;
    }
    return answer;
}