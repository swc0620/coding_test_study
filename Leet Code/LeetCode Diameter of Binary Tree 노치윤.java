class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        int right_depth=depth(root.right);
        int left_depth=depth(root.left);
        int notpassroot_left=(diameterOfBinaryTree(root.left));
        int notpassroot_right=(diameterOfBinaryTree(root.right));
        return Math.max(right_depth+left_depth,Math.max(notpassroot_left,notpassroot_right));
        
    } 
    private int depth(TreeNode root){
        if(root==null) return 0;
        int rightdepth=depth(root.right)+1;
        int leftdepth=depth(root.left)+1;
        return rightdepth>leftdepth?rightdepth:leftdepth;
    }
    

}