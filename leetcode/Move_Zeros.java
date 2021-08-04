class Solution {
  public void moveZeroes(int[] nums) {
      if (nums == null || nums.length <= 1)
          return;
      
      int zero_to_replace = -1;
      
      for (int i=0; i<nums.length; ++i) {
          if (nums[i] != 0) { // start swap
              nums[++zero_to_replace] = nums[i]; // prefix increment
              if (i != zero_to_replace)
                  nums[i] = 0; // replace
          }
      }
      
      
      /*
      i = 0; last = -1; [0,1,0,3,12]
      i = 1; last = 0; [1,0,0,3,12]
      ...
      i = 3; last = 1; [1,3,0,0,12]
      */
  }
}

/**
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Move Zeroes.
Memory Usage: 38.7 MB, less than 99.30% of Java online submissions for Move Zeroes.
 */