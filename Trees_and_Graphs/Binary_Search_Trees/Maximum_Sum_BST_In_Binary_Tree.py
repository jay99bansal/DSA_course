# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    maxBstSum = 0

    def dfs(self, root):
        if not root:
            return {'max': -100000, 'min': 100000, 'sum': 0, 'isBST': True}
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        ans = {}
        ans['max'] = max(l['max'], r['max'], root.val)
        ans['min'] = min(l['min'], r['min'], root.val)
        ans['sum'] = l['sum'] + r['sum'] + root.val
        ans['isBST'] = False
        if l['isBST'] and r['isBST'] and root.val > l['max'] and root.val < r['min']:
            ans['isBST'] = True
            self.maxBstSum = max(self.maxBstSum, ans['sum'])
        return ans

    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.maxBstSum
