class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: # n이 1일 때 바로 종료
            return 1
        
        dp = [[0] for x in range(n + 1)] # dp[0]은 무시
        dp[1], dp[2] = 1, 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        
        return dp[-1]
