# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        stack = [(root.left, root.right)]
        
        while stack:
            left, right = stack.pop(0)
            
            if not left and not right:
                continue
            elif not left or not right:
                return False
            elif left.val == right.val:
                stack.insert(0, (left.left, right.right))
                stack.insert(0, (left.right, right.left))
            else:
                return False
        return True