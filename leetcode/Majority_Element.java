class Solution {
    public int majorityElement(int[] nums) {
        int ME = nums[0];
        int cnt = 1;
        
        for (int num : nums) {
            if (num == ME)
                ++cnt;
            else
                --cnt;
            
            // ME is not majority
            if (cnt == 0) { 
                ME = num; // assign num to ME, start counting again
                cnt = 1;
            }
        }
        
        return ME; // the ME after whole iteration must have cnt > 0
    }
}

/**
 * Runtime: 1 ms, faster than 99.89% of Java online submissions for Majority Element.
 * Memory Usage: 45.3 MB, less than 24.06% of Java online submissions for Majority Element.
 */