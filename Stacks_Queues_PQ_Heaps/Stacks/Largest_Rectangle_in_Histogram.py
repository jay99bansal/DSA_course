from collections import deque
from typing import List

def nsel(nums):
    s = deque()
    ans = []
    for i, n in enumerate(nums):
        while s and s[-1][0]>=n:
            s.pop()
        if s:
            ans.append(s[-1])
        else:
            ans.append((-1, -1))
        s.append((n, i))
    return ans

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        l = nsel(heights)
        r = nsel(heights[::-1])
        r.reverse()
        ans = 0
        for i, h in enumerate(heights):
            val = h*(len(heights)-r[i][1]-l[i][1]-2)
            ans = max(ans, val)
        return ans