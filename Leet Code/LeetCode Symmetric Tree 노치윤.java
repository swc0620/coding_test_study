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
    List<Integer> list_left=new ArrayList<>();
    List<Integer> list_right=new ArrayList<>();
    public List<Integer> left_Traversal(TreeNode root) {
        if(root==null){
            return list_left;
        }
        list_left.add(root.val);
        if(root.left!=null){
            list_left=left_Traversal(root.left);
        }
        else{
            list_left.add(0);
        }

        if(root.right!=null){
            list_left=left_Traversal(root.right);
        }
        else{
            list_left.add(0);
        }

        return list_left;
    }
    public List<Integer> right_Traversal(TreeNode root) {
        if(root==null){
            return list_right;
        }
        list_right.add(root.val);
        if(root.right!=null){
            list_right=right_Traversal(root.right);
        }
        else{
            list_right.add(0);
        }
        if(root.left!=null){
            list_right=right_Traversal(root.left);
        }
        else{
            list_right.add(0);
        }
        return list_right;
    }
    
    public boolean isSymmetric(TreeNode root) {
        
        left_Traversal(root.left);
        right_Traversal(root.right);
        if(list_left.size()!=list_right.size()){
            return false;
        }
        for(int i=0;i<list_left.size();i++){
            System.out.println(list_left.get(i));
            System.out.println(list_right.get(i));
            if(list_left.get(i)!=list_right.get(i))
                return false;
        }
        return true;
    }
}