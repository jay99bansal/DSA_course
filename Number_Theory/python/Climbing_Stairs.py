
def mul(a, b):
    c = []
    for i in range(len(a)):
        row = []
        for j in range(len(b)):
            row.append(0)
            for k in range(len(a)):
                row[-1] += a[i][k]*b[k][j]
        c.append(row)
    return c
def pow(a, b):
    if b==0:
        return [[1, 0], [0, 1]]
    ans = pow(a, b//2)
    ans = mul(ans, ans)
    if b%2!=0:
        ans = mul(ans, a)
    return ans
class Solution:
    def climbStairs(self, n: int) -> int:
        m = [[1,1],[1,0]]
        if n==1:
            return 1
        if n==2:
            return 2
        m = pow(m, n-2)
        return 2*m[0][0]+m[0][1] 
