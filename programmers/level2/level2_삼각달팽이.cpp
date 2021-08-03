#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001] = {0, };
    int x = 0, y = 0, state = 0, num = 1;
    
    for(int i = 0; i < n; i++){ // 0 -> 1 --> 2 --> 0 --> 1 ... 순으로
        switch(state){
            case 0: // 아래로 채우는 방향
                for(int j = i; j < n; j++)
                    arr[x++][y] = num++;
                x--;
                y++;
                state = 1;
                break; // case 1로 넘어갈 때, i 값을 하나 올려주기 위함(꼭 필요)
            case 1: // 오른쪽으로 채우는 방향
                for(int j = i; j < n; j++)
                    arr[x][y++] = num++;
                x--;
                y -= 2;
                state = 2;
                break;
            case 2: // 위로 채우는 방향
                for(int j = i; j < n; j++)
                    arr[x--][y--] = num++;
                x += 2;
                y++;
                state = 0;
                break;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}