class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0 for _ in nums]
        for idx, num in enumerate(nums):
            dp[idx] = max(dp[idx-1]+num, num)
            
        return max(dp)