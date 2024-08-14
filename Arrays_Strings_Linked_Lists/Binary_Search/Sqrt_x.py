class Solution:
    def mySqrt(self, x: int) -> int:
        """
        Time Complexity : O(log n)
        Space Complexity : 0(1)
        """

        left = 0
        right = x
        res = 0

        while left <= right:

            # to prevent over flow .
            mid = left + (right - left) // 2
            squared = mid**2

            # Res will keep track of the value to be returned if value goes out of bounds of the target.

            if x < squared:
                right = mid - 1

            elif x > squared:
                res = mid
                left = mid + 1
            else:
                return mid

        return res


if __name__ == "__main__":
    x = 4
    ans = 2

    result = Solution().mySqrt(x=x)
    print(result)
