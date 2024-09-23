from collections import defaultdict
from typing import List

class Solution:
    al = defaultdict(list)
    colors = ''
    uc = set()
    vis = []
    cycle = set()
    dp = {}

    def dfs(self, node):
        if self.vis[node] or not self.al[node]:
            return False
        self.cycle.add(node)
        for c in self.al[node]:
            if c in self.cycle:
                return True
            if not self.vis[c]:
                if self.dfs(c):
                    return True
        self.vis[node] = True
        self.cycle.remove(node)
        return False
    
    def max_colors(self, node):
        if node in self.dp:
            return self.dp[node]
        self.dp[node] = defaultdict(int)
        for c in self.al[node]:
            ac = self.max_colors(c)
            for color in self.uc:
                self.dp[node][color] = max(self.dp[node][color], ac[color])
        self.dp[node][self.colors[node]] += 1
        return self.dp[node]

    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        self.colors = colors
        self.uc = set(colors)
        self.vis = [False]*n
        self.cycle.clear()
        self.dp.clear()
        self.al.clear()
        for edge in edges:
            self.al[edge[0]].append(edge[1])
        for node in range(n):
            if self.dfs(node):
                return -1
        ans = 0
        for node in range(n):
            ans = max(ans, max(list(self.max_colors(node).values())))
        return ans
