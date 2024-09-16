#User function Template for python3

class Solution:
    def palindromicPartition(self, s):
        n = len(s)
        p = [[False]*n for _ in range(n)] # n x n matrix
        for i in range(n): # Length 1 substrings
            p[i][i] = True
        for i in range(n-1): # Length 2 substrings
            p[i][i+1] = (s[i]==s[i+1])
        for l in range(3, n+1): # Length 3 to n
            for i in range(n-l+1):
                j = i+l-1
                p[i][j] = (s[i]==s[j] and p[i+1][j-1])
        
        dp = []
        for i in range(n):
            if p[0][i]:
                dp.append(0)
            else:
                ans = 5000
                for j in range(i):
                    if p[j+1][i]:
                        ans = min(ans, dp[j]+1)
                dp.append(ans)
        return dp[-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        string = input()
        
        ob = Solution()
        print(ob.palindromicPartition(string))
# } Driver Code Ends