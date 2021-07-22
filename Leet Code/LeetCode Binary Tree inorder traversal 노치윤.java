class Solution {
    List<Integer> list=new ArrayList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root==null){
            return list;
        }
        if(root.left!=null){
            list=inorderTraversal(root.left);
        }
        list.add(root.val);
        if(root.right!=null){
            list=inorderTraversal(root.right);
        }
        return list;
    }
}