class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [float('inf')] * len(nums)
        dp[0] = 0
        for idx, num in enumerate(nums):
            for n in range(num):
                if idx+n+1 < len(nums):
                    dp[idx+n+1] = min(dp[idx+n+1], dp[idx]+1)
        return dp[len(nums)-1]
                