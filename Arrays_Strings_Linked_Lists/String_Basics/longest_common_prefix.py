from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        """
        Time Complexity : O(nLogn + k) -> k = min(len(strs[0])) i.e smallest element
        Space Complexity: O(n) -> for storing sorted array
        """

        ans = ""
        # Sort the list based on lexicographical/ alphabetically
        strs = sorted(strs)

        # If left and right items of the list have common prefix,
        # the longest common prefix would be same has the shortest element.
        # We set two pointed to check that.
        left = strs[0]
        right = strs[-1]

        # Iterating over char_index for each strings.
        for char_idx in range(len(left)):
            # If does not match return
            if left[char_idx] != right[char_idx]:
                return ans
            # else append to answer string.
            ans += left[char_idx]

        return ans
