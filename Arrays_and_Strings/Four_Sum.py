from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        i = 0
        nums.sort()
        n = len(nums)
        while i<n-3:
            j = i+1
            while j<n-2:
                a = j+1
                b = n-1
                while a<b:
                    val = nums[a]+nums[b]+nums[i]+nums[j]
                    if val < target:
                        a+=1
                    elif val > target:
                        b-=1
                    else:
                        ans.append([nums[i], nums[j], nums[a], nums[b]])
                        a += 1
                        b -= 1
                        while a<b and nums[a]==nums[a-1]:
                            a += 1
                        while a<b and nums[b]==nums[b+1]:
                            b -= 1
                j += 1
                while j<n-2 and nums[j]==nums[j-1]:
                    j += 1
            i += 1
            while i<n-3 and nums[i]==nums[i-1]:
                i += 1
        return ans
