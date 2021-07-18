#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
int Answer;
bool Select[8] = {false};
char ItoC[8] = { 'A','C','F','J','M','N','R','T' };
 
void DFS(int Cnt, char Arr[], vector<string> data){
    if (Cnt == 8){
        for (int i = 0; i < data.size(); i++){
            char N1 = data[i][0];           // 조건을 제시한 프렌즈
            char N2 = data[i][2];           // 상대방
            char Cond = data[i][3];         // {=, <, >}
            int Dist = (data[i][4] - '0')+1;    // 거리 (정수로 변환)
            int Idx, IIdx;
            Idx = IIdx = -1;
            for (int j = 0; j < 8; j++){
                if (Arr[j] == N1) Idx = j;
                if (Arr[j] == N2) IIdx = j;
                if (Idx != -1 && IIdx != -1) break;
            }
            if (Cond == '=' && abs(Idx - IIdx) != Dist) return;
            if (Cond == '<' && abs(Idx - IIdx) >= Dist) return;
            if (Cond == '>' && abs(Idx - IIdx) <= Dist) return;
        }
        Answer++;
        return;
    }
    for (int i = 0; i < 8; i++){
        if (Select[i] == true) continue;
        Select[i] = true;
        Arr[Cnt] = ItoC[i];
        DFS(Cnt + 1, Arr, data);
        Select[i] = false;
    }
}
 
int solution(int n, vector<string> data){
    char Arr[8] = { NULL, };
    Answer = 0;
    DFS(0, Arr, data);
    return Answer;
}

int main() {
    int n = 2;
    vector<string> data;
    data.push_back("N~F=0");
    data.push_back("R~T>2");
    cout << solution(2, data);

    return 0;
}
