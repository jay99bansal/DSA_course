from typing import List

class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        """
        Brute Force Method with sorting.

        Time Complexity : O(nlogn + n^2) [sorting (Tim Sort) : nlogn]
        Space Complexity : O(s) [s = len(subsequences)]

        """
        # Sorting the keys based on length of elements
        words = sorted(words,key = len)
        
        # Initialize variables
        result = set()
        n = len(words) 
        i = 0

        # First loop to iterate over every element. 
        for i in range(n):
            # Second loop to take the next elements from the starting index.
            for i_next in range(i+1,n):
                
                # As the list is non-decreasing order, check if starting index is
                # in the next index.
                if words[i] in words[i_next] :
                    result.add(words[i])
                else:
                    continue

            
        return list(result)

        

if __name__ == "__main__":

    words = ["leetcoder","leetcode","od","hamlet","am"]
    output = ["am","leetcode","am"]
    answer = Solution().stringMatching(words=words)
    print(answer)

    # Check if answer is as expected
    assert output == answer