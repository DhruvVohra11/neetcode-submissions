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
    bool trav(TreeNode * root, TreeNode * subRoot){
        if(!root and !subRoot) return true;
        if(!root or !subRoot) return false;
        if(root->val == subRoot->val){
            return trav(root->left, subRoot->left) and trav(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //traverse the tree till the first node matches then start
        if(!root || !subRoot) return false;
        if(trav(root,subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};
