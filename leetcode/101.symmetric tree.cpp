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
    void dfs(TreeNode* root, int length,int &maxx){
        if(root==NULL){
            maxx = max(maxx,length);
            return;
        }
        length++;
        dfs(root->left,length,maxx);
        dfs(root->right,length,maxx);
    }
    
    int maxDepth(TreeNode* root) {
        int maxx = 0;
        dfs(root,0,maxx);
        return maxx;
    }
};

/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return  true;
        return isSame(root->left,root->right);  
    }
    
    bool isSame(TreeNode* left, TreeNode* right){
        if(left==NULL){
            if(right==NULL)return true;
            else return false;
        }
        else{
            if (right==NULL){
                return false;
            }
            else {
                if (left->val==right->val){
                    return isSame(left->left,right->right) && isSame(left->right,right->left);
                }
                else {
                    return false;
                }
            }
        }
    }
};
*/