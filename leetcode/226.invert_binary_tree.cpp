class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* t = root->left;
        root->left = root->right;
        
        root->right = t;
        
        return root;
        
    }
};