class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        // If this is the FIRST time we have reached this depth layer,
        // this node must be the rightmost visible node of this level!
        if (depth == ans.size()) {
            ans.push_back(node->val);
        }

        // CRITICAL ORDER: Always explore the right side first!
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        dfs(root, 0);
        return ans;
    }
};