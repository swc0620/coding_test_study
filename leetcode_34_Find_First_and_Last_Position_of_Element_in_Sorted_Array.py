class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def binarySearchFindPos(nums, target, find_start):
            low, high, res = 0, len(nums) - 1, -1
            while(low <= high):
                mid = (low + high) // 2
                if nums[mid] == target:
                    res = mid
                    if find_start:
                        high = mid - 1
                    else:
                        low = mid + 1
                elif nums[mid] > target:
                    high = mid - 1
                elif nums[mid] < target:
                    low = mid + 1
            return res
        
        start = binarySearchFindPos(nums, target, True)
        end = binarySearchFindPos(nums, target, False)
        return [start, end]