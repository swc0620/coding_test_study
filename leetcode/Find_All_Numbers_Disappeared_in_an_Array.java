class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        ArrayList<Integer> answer = new ArrayList<>();
        int n = nums.length;
        
        for (int i=0; i<n; ++i) {
            int num = Math.abs(nums[i]);
            if (nums[num-1] > 0) // num in range [1,n] has appeared; if duplicate, continues loop
                nums[num-1] *= -1; // mark it negative
        }
        
        for (int i=0; i<n; ++i)
            if (nums[i] > 0) // hasn't been marked negative
                answer.add(i+1);
        
        return answer;
    }
}

/**
 * Runtime: 5 ms, faster than 78.92% of Java online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 48 MB, less than 61.13% of Java online submissions for Find All Numbers Disappeared in an Array.
 */