import deque # type: ignore
from typing import List

class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        n = len(graph)
        dp = {}
        for i in range(1, n):
            dp[(0, i, 1)] = dp[(0, i, 2)] = 1 # Mouse wins
            dp[(i, i, 1)] = dp[(i, i, 2)] = 2 # Cat wins

        od = {} # Outdegree of every state
        for m in range(1, n):
            for c in range(1, n):
                od[(m, c, 1)] = len(graph[m])
                od[(m, c, 2)] = len(graph[c])
                if 0 in graph[c]:
                    od[(m, c, 2)] -= 1

        q = deque([state for state in dp.keys()])
        while q:
            (m, c, move) = q.popleft()
            ca = dp[(m, c, move)]
            ps = []
            if move == 1:
                ps = [(m, pc, 2) for pc in graph[c] if pc!=0]
            else:
                ps = [(pm, c, 1) for pm in graph[m]]

            for p in ps:
                if p in dp:
                    continue
                (pm, pc, pmove) = p
                od[p] -= 1
                if (ca==1 and pmove==1) or (ca==2 and pmove==2) or od[p]==0:
                    dp[p] = ca
                    q.append(p)
        
        if (1, 2, 1) in dp:
            return dp[(1, 2, 1)]
        return 0