from collections import deque
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        level = 0
        if not root:
            return 0
        q = deque([root])
        
        while q:
            level += 1
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)

                if node.right:
                    q.append(node.right)
            
        return level
