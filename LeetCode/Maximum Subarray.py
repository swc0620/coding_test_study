class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = nums
        for i in range(1, len(nums)):
            result[i] = max(result[i - 1] + nums[i], nums[i])
        
        return max(result)
