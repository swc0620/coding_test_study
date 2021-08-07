/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
    
private:
    int depth(TreeNode* root, int& diameter) {
        if (root == NULL) { // !root
            return 0;
        }
        
        int l = depth(root -> left, diameter);
        int r = depth(root -> right, diameter);
        diameter = max(diameter, l + r);
        
        return max(l, r) + 1; 
    }
};