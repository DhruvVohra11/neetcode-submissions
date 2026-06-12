class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 1. Base Case: If we hit a leaf's child (None), stop.
        if not root:
            return None
        
        # 2. The Work: Swap the left and right subtrees
        root.left, root.right = root.right, root.left
        
        # 3. The Recursion: Go down and do the same for the children
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        # Always return the root at the end
        return root