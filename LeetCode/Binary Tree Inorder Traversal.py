class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        answer = []
        if root == None:
            return answer
        
        if root.left:
            answer.extend(self.inorderTraversal(root.left))
            
        if root != None:
            answer.extend([root.val])
        
        if root.right:
            answer.extend(self.inorderTraversal(root.right))
        
        return answer
