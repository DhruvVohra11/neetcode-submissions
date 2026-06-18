
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* prev = nullptr; // Keeps track of the previously visited node

        while (curr != nullptr || !s.empty()) {
            // 1. Go as far left as possible
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            // 2. Process the current node
            curr = s.top();
            s.pop();

            // CRITICAL CHECK: Current value must be strictly greater than the previous value
            if (prev != nullptr && curr->val <= prev->val) {
                return false;
            }
            
            prev = curr; // Move our previous pointer to the current node

            // 3. Move to the right child
            curr = curr->right;
        }

        return true;
    }
};