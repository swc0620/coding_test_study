class Solution {
    public int maxSubArray(int[] nums) {
        int ans = nums[0];
        int currSum = nums[0];
        for (int i=1; i<nums.length; ++i) {
            currSum = Math.max(nums[i], currSum + nums[i]); // overwhelm?
            ans = currSum > ans ? currSum : ans; // update max?
            // cf) Math.max is slow
        }
        return ans;
    }
}