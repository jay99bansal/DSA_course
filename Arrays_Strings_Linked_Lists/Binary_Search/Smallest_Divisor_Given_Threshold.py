from typing import List

def bs(nums, t, l, r):
    if l == r:
        return l
    m = (l+r)//2
    s = 0
    for n in nums:
        s += n//m
        if n%m != 0:
            s += 1
    if s <= t:
        return bs(nums, t, l, m)
    else:
        return bs(nums, t, m+1, r)

class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        return bs(nums, threshold, 1, max(nums))