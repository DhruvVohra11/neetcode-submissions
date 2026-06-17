# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0
        
        def get_height(node):
            if not node:
                return 0
            
            # 1. Ask left and right subtrees for their heights
            left_height = get_height(node.left)
            right_height = get_height(node.right)
            
            # 2. Update the global maximum diameter found so far
            self.max_diameter = max(self.max_diameter, left_height + right_height)
            
            # 3. Return the height of the current node to its parent
            return 1 + max(left_height, right_height)
        
        get_height(root)
        return self.max_diameter
