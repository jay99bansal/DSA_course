class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        Sliding Window Method:

        Time Complexity : O(n)
        Space Complexity : O(1) + 0(1)

        """
        needle_len = len(needle)
        haystack_len = len(haystack)
        i = 0

        while (i + needle_len) <= haystack_len:

            if haystack[i : i + needle_len] == needle:
                return i
            else:
                i = i + 1

        return -1


if __name__ == "main":
    
    haystack = "sadbutsad"
    needle = "sad"

    answer = Solution().strStr(haystack=haystack,needle=needle)
    print("Answer:",answer)
    
    result = 0 
    assert answer == result 