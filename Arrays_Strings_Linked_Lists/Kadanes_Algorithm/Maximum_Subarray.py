from typing import List

class Solution:
    
    def maxSubArrayApproach1(self, nums: List[int]) -> int:
        """
            Time Complexity : O(n)
            Space Complexity : O(1)
        """

        # Initialize  variables
        sum = 0
        ans = int(-1e9-1)

        # Running loop from start to end of array
        for n in nums:
            # calculating current sum 
            sum += n

            # finding maximum value of all current sums 
            ans = max(ans, sum)

            # updating sum if it turns negative.
            sum = max(0, sum)

        return ans
    
    def maxSubArrayApproach2(self, nums: List[int]) -> int:
        """
            Time Complexity : O(n)
            Space Complexity : O(1)

        """

        # Initialize variables
        curr_sum = 0
        max_sum = nums[0]
        n = len(nums) 

        # Running loop till end of the nums array
        for i in range(n):

            # setting current sum as ) if it goes negative.
            if curr_sum < 0:
                curr_sum = 0

            # Calculating current sum with index
            curr_sum = curr_sum + nums[i]

            #Finding maximum sum of the array. 
            max_sum = max(curr_sum,max_sum)
            
        return max_sum


if __name__ == "__main__":

    nums = [-2,1,-3,4,-1,2,1,-5,4]

    answer1 = Solution().maxSubArrayApproach1(nums=nums)
    print(answer1)


    answer2 = Solution().maxSubArrayApproach2(nums=nums)
    print(answer2)