/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return null;
        
        // bottom-up approach
        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);
        // swap children
        root.left = right;
        root.right = left;
        
        return root;
    }
}

/**
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Invert Binary Tree.
 * Memory Usage: 36.7 MB, less than 23.27% of Java online submissions for Invert Binary Tree.
 */