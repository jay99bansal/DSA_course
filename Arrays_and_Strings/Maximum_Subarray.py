from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        ans = int(-1e9-1)
        for n in nums:
            sum += n
            ans = max(ans, sum)
            sum = max(0, sum)
        return ans
