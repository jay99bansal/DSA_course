#User function Template for python3

def bs(piles, H, l, r):
    if l==r:
        return l
    m = (l+r)//2
    h = 0
    for p in piles:
        h += p//m
        if p%m != 0:
            h += 1
    if h <= H:
        return bs(piles, H, l, m)
    else:
        return bs(piles, H, m+1, r)

class Solution:
    def Solve(self, N, piles, H):
        return bs(piles, H, 1, max(piles))
