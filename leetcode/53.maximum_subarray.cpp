class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxHere = 0;
        int maxSoFar = nums[0];
        
        if(nums.size() == 1)
            return nums[0];
        
        for(int i = 0;i<nums.size();i++){
            maxHere += nums[i];
            maxSoFar = max(maxSoFar, maxHere);
            maxHere = max(maxHere, 0);
        }
        return maxSoFar;
    }
};