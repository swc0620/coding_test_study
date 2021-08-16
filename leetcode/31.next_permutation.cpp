class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        
        int idx = -1;
        for(int i = len - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        
        if (idx != -1) {
            int swapInd = -1;
            int val = INT_MAX;
            for(int i = idx + 1; i < len; i++) {
                if(nums[i] > nums[idx]) {
                    if(nums[i] <= val) {
                        swapInd = i;
                    }
                }
            }
            swap(nums[idx],nums[swapInd]);
            sort(nums.begin() + idx + 1, nums.end());
        }
        else {
            sort(nums.begin(), nums.end());
        }
    }
};


/*

1 3 2 5

5 1 3 2
5 3 1 2

*/