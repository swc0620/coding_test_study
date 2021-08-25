#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int max_check(vector<int>& v, int idx){
    int temp = 0;
    for(int i = 0; i < 4; i++)
        if(i != idx)
            temp = max(temp, v[i]);
    return temp;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for(size_t i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            land[i][j] += max_check(land[i - 1], j);
            answer = max(answer, land[i][j]);
        }
    }
    return answer;


/* 
두번째 행부터 시작하여 계산
[5, 6, 7, 8] 이 있으면 첫번 째 행은 [1, 2, 3, 5]

[5, 6, 7, 8] 부분은 [x, 2, 3, 5] 덧셈이 가능해진다.
여기서 제일 큰 부분은 5이므로 계산해보면 [10, 6, 7, 8]
나머지 값들을 계산하면 [10, 11, 12, 11]

*/