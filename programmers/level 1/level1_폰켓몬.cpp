#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> count;
    
    for (int i=0; i<nums.size(); i++){
        count.insert(nums[i]);
    }
    
    return min(count.size(), nums.size()/2);
    
    // [3, 1, 2, 3] -> set에는 {1, 2, 3}이 담기는데, 최대 2개만 가질 수 있기 때문에
    // min(count.size(), nums.size()/2)
        
    // if (nums.size() / 2 >= count.size()){
    //     return count.size();
    // }
    // else{
    //     return nums.size()/2;
    // }
}