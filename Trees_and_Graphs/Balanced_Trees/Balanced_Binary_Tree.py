# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    maxBalancingFactor = 0

    def dfs(self, root):
        if not root:
            return 0
        ld = self.dfs(root.left)
        rd = self.dfs(root.right)
        self.maxBalancingFactor = max(self.maxBalancingFactor, abs(ld-rd))
        return max(ld, rd)+1
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.dfs(root)
        return self.maxBalancingFactor <= 1