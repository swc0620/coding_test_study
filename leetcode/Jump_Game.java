class Solution {
  public boolean canJump(int[] nums) {
      int end = nums.length - 1;
      int maxIndex = nums[0];
      
      for (int i=0; i<=maxIndex; ++i) {
          maxIndex = Math.max(maxIndex, i+nums[i]); // reachable from i
          if (maxIndex >= end)
              return true;
      }
      
      return false;
  }
}