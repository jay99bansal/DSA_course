from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        c1 = 0
        c2 = 0
        x1 = 1e9+1
        x2 = 1e9+1
        for n in nums:
            if n!=x2 and c1==0:
                c1 = 1
                x1 = n
            elif n!=x1 and c2==0:
                c2 = 1
                x2 = n
            elif n==x1:
                c1 += 1
            elif n==x2:
                c2 += 1
            else:
                c1 -= 1
                c2 -= 1
        c1 = 0
        c2 = 0
        for n in nums:
            if n==x1:
                c1 += 1
            elif n==x2:
                c2 += 1
        ans = []
        if c1 > len(nums)//3:
            ans.append(x1)
        if c2 > len(nums)//3:
            ans.append(x2)
        return ans