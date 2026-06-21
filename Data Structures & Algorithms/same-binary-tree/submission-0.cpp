class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. Base Cases
        if (p == nullptr && q == nullptr) return true;  // Both empty -> structurally matching
        if (p == nullptr || q == nullptr) return false; // One is empty, one isn't -> mismatch
        if (p->val != q->val) return false;             // Values don't match -> mismatch
        
        // 2. Trust your children and combine results
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};