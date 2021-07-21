# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversalInternal(self, root: TreeNode, result: List[int]):
        if not root:
            return
        else:
            self.inorderTraversalInternal(root.left, result)
            result.append(root.val)
            self.inorderTraversalInternal(root.right, result)
            
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        self.inorderTraversalInternal(root, result)
        return result