class Solution {
  public int[] countBits(int n) {
      if (n == 0)
          return new int[1];
      
      int[] dp = new int[n+1];
      dp[0] = 0;
      dp[1] = 1;
      for (int i=2; i<=n; ++i) {
          if ((i & 1) == 0) // even
              dp[i] = dp[i/2];
          else
              dp[i] = dp[i/2] + 1;
      }
      
      return dp;
  }
}

/*
Runtime: 1 ms, faster than 99.85% of Java online submissions for Counting Bits.
Memory Usage: 43.4 MB, less than 38.28% of Java online submissions for Counting Bits.
*/
