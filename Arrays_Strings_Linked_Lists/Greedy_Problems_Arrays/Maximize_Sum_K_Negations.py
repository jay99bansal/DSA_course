import heapq
from typing import List

class Solution:
    # T: O(n+klog(n))
    # S: O(1)
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)  # Creates a min heap by default O(n)
        for _ in range(k):   # O(klog(n))
            heapq.heappush(nums, -heapq.heappop(nums))
        return sum(nums) # O(n)