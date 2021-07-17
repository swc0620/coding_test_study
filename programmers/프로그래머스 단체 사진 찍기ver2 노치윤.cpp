#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Answer;

void DFS(vector<char> Arr, vector<string> data)
{
    do {
        int check = 0;
        for (int i = 0; i < data.size(); i++) {
            char first = data[i][0];
            char second = data[i][2];
            char oper = data[i][3];
            int distance = data[i][4] - '0' + 1;

            int first_idx = -1;
            int second_idx = -1;
            for (int j = 0; j < 8; j++) {
                if (Arr[j] == first) first_idx = j;
                if (Arr[j] == second) second_idx = j;
                if (first_idx != -1 && second_idx != -1) break;
            }

            if (oper == '=' && abs(first_idx - second_idx) != distance) {
                check = 1;
                break;
            }
            if (oper == '>' && abs(first_idx - second_idx) <= distance) {
                check = 1;
                break;
            }
            if (oper == '<' && abs(first_idx - second_idx) >= distance) {
                check = 1;
                break;
            }
        }
        if (check == 0) {
            Answer++;
        }
    } while (next_permutation(Arr.begin(), Arr.end()));


}

int solution(int n, vector<string> data)
{
    Answer = 0;
    vector<char> Arr = { 'A','C','F','J','M','N','R','T' };
    DFS(Arr, data);
    return Answer;
}