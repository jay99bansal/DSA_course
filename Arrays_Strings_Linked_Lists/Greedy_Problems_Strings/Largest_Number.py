from functools import cmp_to_key
from typing import List

def comp(a, b):
    if a+b > b+a:
        return -1
    return 1

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = list(map(str, nums))
        nums = sorted(nums, key = cmp_to_key(comp))
        ans = ''.join(nums).lstrip("0")
        if not ans:
            ans = "0"
        return ans