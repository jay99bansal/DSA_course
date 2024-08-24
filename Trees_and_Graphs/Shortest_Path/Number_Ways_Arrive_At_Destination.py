import heapq
from typing import List

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        MOD = int(1e9+7)
        adj = [{} for _ in range(n)]
        for [u, v, w] in roads:
            adj[u][v] = w
            adj[v][u] = w
        pq = [(0, 0)]
        w = [0]*n
        w[0] = 1
        dis = [int(1e18)]*n
        dis[0] = 0

        while pq:
            (du, u) = heapq.heappop(pq)
            for v in adj[u]:
                if du + adj[u][v] < dis[v]:
                    dis[v] = du + adj[u][v]
                    heapq.heappush(pq, (dis[v], v))
                    w[v] = w[u]
                elif du + adj[u][v] == dis[v]:
                    w[v] = (w[u] + w[v])%MOD
        
        return w[n-1]