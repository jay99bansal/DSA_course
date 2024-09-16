from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        r = [0]*n
        nr = [0]*n
        r[0] = nums[0]
        for i in range(1, n):
            r[i] = nr[i-1]+nums[i]
            nr[i] = max(r[i-1], nr[i-1])
        print(r)
        print(nr)
        return max(r[n-1], nr[n-1])