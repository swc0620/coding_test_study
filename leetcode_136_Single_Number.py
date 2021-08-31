class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        alist = []
        for idx, num in enumerate(nums):
            if not alist:
                alist.append(num)
            else:
                if num in alist:
                    alist.remove(num)
                else:
                    alist.append(num)
        return alist[0]