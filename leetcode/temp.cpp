#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int singleNumber(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    for (auto num: nums){
        cout << num << " ";
    }
    for (int i=0; i<nums.size(); i+=2){
        if (nums[i] == nums[i+1]){
            continue;
        }
        else{
            return nums[i];
        }
    }
    return nums[nums.size()-1];
}

int main (){
    vector<int> nums = {-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,354};
    
    int answer = singleNumber(nums);

    cout << answer;
    return 0;
}