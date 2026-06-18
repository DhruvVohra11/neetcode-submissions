# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(node: Optional[TreeNode]):
            if node:
                l = height(node.left)
                r = height(node.right)
                return 1+max(l,r)
            return 0
        if not root :
            return True
        if root:
            diff = height(root.left)-height(root.right)
        else :
            diff = 0 
        if abs(diff) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)