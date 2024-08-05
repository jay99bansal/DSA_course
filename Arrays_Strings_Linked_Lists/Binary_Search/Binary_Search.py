from typing import List

def bs(nums, l, r, target):
    if l == r:
        if nums[l] == target:
            return l
        else:
            return -1
    m = (l+r)//2
    if nums[m] >= target:
        return bs(nums, l, m, target)
    else:
        return bs(nums, m+1, r, target)

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return bs(nums, 0, len(nums)-1, target)