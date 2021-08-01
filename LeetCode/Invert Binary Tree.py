# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def dfs(root: TreeNode):
            if not root:
                return None
            
            dfs(root.left)
            dfs(root.right)
            
            root.left, root.right = root.right, root.left
        
        dfs(root)
        return root
