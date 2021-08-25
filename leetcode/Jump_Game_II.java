class Solution {
  public int jump(int[] nums) {
      int n = nums.length, jumps = 0;
      int prevMax = 0; // maximum possible index reachable by taking jumps
      int currMax = 0; // 
      if (n <= 1) // no need to jump
          return jumps;
      
      for (int i=0; i<n-1; ++i) {
          currMax = Math.max(currMax, i + nums[i]); // previous farthest distance vs new distance to reach with current maximum jump length
          if (i == prevMax) { // ith position can be reached by prevMax, meaning this is included in min num of jumps
              ++jumps; // jump to i using prevMax
              prevMax = currMax;
          }
      }
      return jumps;
  }
}