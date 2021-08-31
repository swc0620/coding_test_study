class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(nums, target, combis, res):
            print(nums, target, combis, res)
            if target < 0:
                return
            elif target == 0:
                res.append(combis)
                return 
            for idx, num in enumerate(nums):
                dfs(nums[idx:], target-num, combis+[num], res)
        
        res = []
        dfs(candidates, target, [], res)
        return res