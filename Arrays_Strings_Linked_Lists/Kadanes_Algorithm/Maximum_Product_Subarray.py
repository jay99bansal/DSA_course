from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        # Initialize variables for forward pass
        i = 0
        n = len(nums)
        max_prod = -1e9-1 # or you can take float(-inf)
        curr_prod = 1

        # Forward pass where you check substring w.r.t to starting index
        while i < n:
            curr_prod  = curr_prod * nums[i]
            max_prod = max(curr_prod,max_prod)
            
            if curr_prod == 0:
                curr_prod = 1
            
            i += 1
        
        # Initialize for Backward Pass
        curr_prod = 1
        i = n - 1       

        # Backward pass , checking substring w.r.t to end index.
        while i >= 0:
            curr_prod = curr_prod * nums[i]
            max_prod = max(curr_prod,max_prod)

            if curr_prod == 0:
                curr_prod = 1
            
            i -= 1
        
        return max_prod



if __name__ == "__main__":

    nums = [2,3,-2,4]

    answer1 = Solution().maxProduct(nums=nums)
    print(answer1)
