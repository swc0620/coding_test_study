# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root: TreeNode, result: List[int], count: int):
        if not root:
            if result:
                result[0] = max(result[0], count-1)
            else:
                result.append(count-1)
            return
        else:
            # inorder traversal
            self.helper(root.left, result, count+1)
            self.helper(root.right, result, count+1)
            
    
    def maxDepth(self, root: TreeNode) -> int:
        result = []
        self.helper(root, result, 1)
        return result[0]
        