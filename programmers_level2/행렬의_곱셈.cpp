#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    // arr1( M * K ), arr2( K * N ) 
    
    for (int i=0; i<arr1.size(); ++i) { // M
        vector<int> row;
        for (int j=0; j<arr2[0].size(); ++j) { // N
            int sum = 0;
            for (int k=0; k<arr1[0].size(); ++k) { // K
                sum += arr1[i][k] * arr2[k][j]; // arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0] + arr1[0][2] * arr2[0][2]
            }
            row.push_back(sum);
        }
        answer.push_back(row);
    }
    
    return answer;
}