def pow(a, b):
    if b==0:
        return 1.0
    ans = pow(a, b//2)
    ans = ans*ans
    if b%2 != 0:
        ans = ans*a
    return ans

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n>=0:
            return pow(x, n)
        else:
            return 1.0/pow(x, -n)
