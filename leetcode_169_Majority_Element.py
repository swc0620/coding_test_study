class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = {}
        for num in nums:
            if num not in count.keys():
                count[num] = 1
            else:
                count[num] += 1
        return max(count, key=count.get)