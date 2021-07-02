#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        temp.insert(nums[i]);
    }
    int nums_size = nums.size();
    int temp_size = temp.size();
    if (nums_size / 2 > temp_size) {
        answer = temp_size;
    }
    else {
        answer = nums_size / 2;
    }
    return answer;
}