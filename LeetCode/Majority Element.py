class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counter = {}
        for num in nums:
            if num in counter.keys():
                counter[num] += 1
                if counter[num] > len(nums) / 2:
                    return num
            else:
                counter[num] = 1
                if counter[num] > len(nums) / 2:
                    return num
