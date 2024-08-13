class Solution:
    # User function Template for python3

    # Complete this function
    def findFloor(self, A, N, X):
        """
        Time Complexity : O(log n)
        Space Complexity : 1
        """

        left = 0
        right = N - 1
        res_index = -1

        while left <= right:
            mid = (left + right) // 2

            # Idea is to return the index if the value is greater or equals
            # to mid value
            if X < A[mid]:
                right = mid - 1

            else:
                res_index = mid
                left = mid + 1

        return res_index


if __name__ == "__main__":
    n = 7
    x = 5 
    arr = [1,2,8,10,11,12,19]
    ans =  1

    result = Solution().findFloor(A=arr,N=n,X=x)
    print(result)