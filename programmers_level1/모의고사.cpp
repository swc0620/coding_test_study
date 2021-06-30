#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> answers) {
    map<int,int> ans{ {1,0}, {2,0}, {3,0} }; // 1, 2, 3번 수포자 맞힌 개수
    int guess1[5]{ 1,2,3,4,5 };
    int guess2[8]{ 2,1,2,3,2,4,2,5 };
    int guess3[10]{ 3,3,1,1,2,2,4,4,5,5 };
    int* guess[3]{ guess1, guess2, guess3 };


    for (int i=0; i<answers.size(); ++i) {
        if (answers[i] == guess[0][i%5]) ++ans[1];
        if (answers[i] == guess[1][i%8]) ++ans[2];
        if (answers[i] == guess[2][i%10]) ++ans[3];
    }

    int best = max(ans[1], max(ans[2], ans[3]));

    vector<int> answer;
    for (int k=1; k<=3; ++k) {
        if (ans[k] == best) {
            answer.push_back(k);
        }
    }

    return answer;
}