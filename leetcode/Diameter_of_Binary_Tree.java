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
  int diameter = 0;
  
  public int diameterOfBinaryTree(TreeNode root) {
      int depthOfRoot = depthOfSubTree(root); // store return value
      return diameter;
  }
  
  private int depthOfSubTree(TreeNode root) {
      if (root == null)
          return 0;
      
      // store values to incur recursion for the first time
      int leftDepth = depthOfSubTree(root.left);
      int rightDepth = depthOfSubTree(root.right);
      diameter = Math.max(diameter, leftDepth + rightDepth);
      
      return Math.max(leftDepth, rightDepth) + 1; // leaf node = depth 1
  }
}

/**
 * Runtime: 0 ms, faster than 100.00% of Java online submissions for Diameter of Binary Tree.
Memory Usage: 38.5 MB, less than 95.00% of Java online submissions for Diameter of Binary Tree.
 */