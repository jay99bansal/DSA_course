from typing import List

class Solution:
    p = [-1]*1001

    def find(self, x):
        if self.p[x] >= 0:
            self.p[x] = self.find(self.p[x])
            return self.p[x]
        return x

    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if pa == pb:
            return False
        ra = -self.p[pa]
        rb = -self.p[pb]
        if ra > rb:
            self.p[pb] = pa
        elif rb > ra:
            self.p[pa] = pb
        else:
            self.p[pa] = pb
            self.p[pb] -= 1
        return True

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        self.p = [-1]*1001
        for e in edges:
            if not self.union(e[0], e[1]):
                return e
        