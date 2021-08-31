class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        stack = [root]
        while stack:
            node = stack.pop(0)
            if node:
                node.left, node.right = node.right, node.left
                stack.insert(0, node.left)
                stack.insert(0, node.right)
        return root