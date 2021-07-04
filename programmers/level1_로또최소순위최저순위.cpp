#include <string>
#include <vector>

using namespace std;

int getRank(int num){
    if (num == 6) return 1;
    else if (num == 5) return 2;
    else if (num == 4) return 3;
    else if (num == 3) return 4;
    else if (num == 2) return 5;
    else return 6;
}

vector<int> solution (vector<int> lottos, vector<int> win_nums){
    vector<int> answer;
    int same = 0;
    int zero = 0;
    for (int i=0; i<lottos.size(); i++){
        if (lottos[i] == 0){
            zero++;
        }
        for (int j=0; j<win_nums.size(); j++){
            if (lottos[i] == win_nums[j]){
                same++;
            }
        }
    }
    
    int max = getRank(same + zero);
    int min = getRank(same);

    answer.push_back(max);
    answer.push_back(min);
    
    return answer;
}