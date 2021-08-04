class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx = 1
        for i, num in enumerate(nums):
            while i+idx < len(nums) and nums[i] == 0 and nums[i + idx] == 0:
                idx += 1
            if i+idx < len(nums):
                if nums[i] == 0:
                    nums[i], nums[i+idx] = nums[i+idx], nums[i]
                else:
                    pass