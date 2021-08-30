#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subvec;

    for (vector<int> command : commands) {
        subvec = { array.begin()+command[0]-1, array.begin()+command[1] };
        sort(subvec.begin(), subvec.end());
        answer.push_back(subvec.at(command[2]-1));
    }

    return answer;
}