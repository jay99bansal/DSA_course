from typing import List

class Solution:
    """
    Time Complexity : O(Log n)
    Space Complexity : O(1)

    """

    def binarySearch(self, nums, target, leftBias):
        left = 0
        right = len(nums) - 1
        i = -1

        while left <= right:
            mid = (right + left) // 2

            if nums[mid] == target:
                i = mid
                # leftBias help you to find keep check in left or right direction.
                # You might go in infinite loop if you do simple binary search.
                # leftBias will help in recuding the left or right pointer each time to get to
                # starting and end index of the range after each split by 2.
                if leftBias:
                    right = mid - 1
                else:
                    left = mid + 1

            elif nums[mid] < target:
                left = mid + 1

            else:
                right = mid - 1

        # we return index if mid matches else -1
        return i

    def searchRange(self, nums: List[int], target: int) -> List[int]:

        # leftBias true as we are looking for left index
        left = self.binarySearch(nums, target, True)
        # leftBias false as we are lookig for right index
        right = self.binarySearch(nums, target, False)

        return [left, right]


if __name__ == "__main__":

    nums = [5, 7, 7, 8, 8, 10]

    ans = Solution().searchRange(nums=nums, target=8)
