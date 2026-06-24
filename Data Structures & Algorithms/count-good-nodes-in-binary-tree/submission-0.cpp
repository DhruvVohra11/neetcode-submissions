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
    int dfs(TreeNode * root, int max){
        if(!root) return 0;
        if(root->val >= max){
            return 1+dfs(root->right, root->val)+dfs(root->left, root->val);
        }
            return dfs(root->right, max)+dfs(root->left,max);
    }
    int goodNodes(TreeNode* root) {
        //top down prob 
        int r = dfs(root->right, root->val);
        int l = dfs(root->left, root->val);
        return r+l+1;

    }
};
