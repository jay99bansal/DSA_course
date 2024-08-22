from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        """
        Time Complexity: O(n)
        Space Complexity: O(n + n) -> one for stack and answer array
        """
        stack = []
        ans = [-1] * len(nums)

        # iterate over nums and populate stack when you see a greater number than top of stack
        # stack would in increaing order
        for idx, num in enumerate(nums):
            # while stack is not empty and
            # top element of stack , index of nums array element
            # is less than the current number
            while stack and nums[stack[-1]] < num:
                # answer array index will be replaced by the value in stack
                ans[stack.pop()] = num

            # Insert index of num in stack
            stack.append(idx)

        # for elements left in the stack , if there are elements and less than current number.
        # pop from top of stack.
        for num in nums:
            while stack and nums[stack[-1]] < num:
                ans[stack.pop()] = num

        return ans


if __name__ == "__main__":
    nums = [1,2,3,4,3]
    ans = Solution().nextGreaterElements(nums)

    output = [2, 3, 4, -1, 4]
    print(ans)

    assert output == ans