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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1. Base Case: Always check for nullptr first!
        if (root == nullptr) return nullptr;

        // 2. Scenario A: Both values are smaller than root -> LCA is on the left
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // 3. Scenario B: Both values are larger than root -> LCA is on the right
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // 4. Scenario C: They split, or root equals p or q. 
        // We found it! Return the current root.
        return root;
    }
};