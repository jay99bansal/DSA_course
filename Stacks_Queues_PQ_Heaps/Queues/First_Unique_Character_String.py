from collections import deque

class Solution:
    def firstUniqChar(self, s: str) -> int:
        q = deque()
        ct = {}
        for i,c in enumerate(s):
            if c in ct:
                ct[c] += 1
            else:
                ct[c] = 1
                q.appendleft(i)
        while q:
            if ct[s[q[-1]]] == 1:
                return q[-1]
            q.pop()
        return -1