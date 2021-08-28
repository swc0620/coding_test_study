#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int k = 0; k < arr1.size(); k++) {
        vector<int> temp;
        for (int i = 0; i < arr2[0].size(); i++) {
            int element = 0;
            for (int j = 0; j < arr2.size(); j++) {
                element += arr1[k][j] * arr2[j][i];
            }
            temp.push_back(element);
        }
        answer.push_back(temp);
    }
    return answer;
}