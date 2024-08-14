from typing import List

class Solution:
    # T = O(n), S = O(n)
    def candy(self, r: List[int]) -> int:
        n = len(r)
        c = [1]*n
        # Left to right pass O(n)
        for i in range(1, n):
            if r[i] > r[i-1]:
                c[i] = c[i-1]+1
        
        # Right to left pass O(n)
        for i in range(n-2, -1, -1):
            if r[i] > r[i+1] and c[i] <= c[i+1]:
                c[i] = c[i+1]+1
        
        return sum(c) #O(n)