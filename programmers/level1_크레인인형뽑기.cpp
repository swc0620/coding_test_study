#include <string>
#include <vector>
 
using namespace std;
 
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int i, j;
    vector<int> stack;
    
    for(i = 0;i<moves.size();i++){
        for(j = 0;j<board.size();j++){
            if(board[j][moves[i] - 1] != 0){
                stack.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                
                if(stack.size() > 1){
                    if(stack[stack.size() - 1] == stack[stack.size() - 2]){
                        stack.pop_back();
                        stack.pop_back();
                        answer++;
                    }
                }
                
                break;
            }
        }
    }
    return answer*2;
}
