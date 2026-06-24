#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ans;
        if (!root) return ans;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();

            // Process all nodes on the current level
            for (int i = 0; i < level_size; i++) {
                auto curr = q.front();
                q.pop();

                // CRITICAL STEP: If this is the LAST node in the current level loop,
                // it is the one visible from the right side!
                if (i == level_size - 1) {
                    ans.push_back(curr->val);
                }

                // Push children for the next level
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return ans;
    }
};