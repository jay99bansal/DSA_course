N = 100000
MOD = 1000000007
f = [1 for _ in range(N+1)]
fi = [1 for _ in range(N+1)]

def pow(a, b):
    if b==0:
        return 1
    ans = pow(a, b//2)
    ans = (ans*ans)%MOD
    if b%2!=0:
        ans = (ans*a)%MOD
    return ans
for i in range(1, N+1):
    f[i] = (i*f[i-1])%MOD
fi[N] = pow(f[N], MOD-2)
for i in range(N-1, -1, -1):
    fi[i] = ((i+1)*fi[i+1])%MOD

def ana(w):
    c = [0 for _ in range(26)]
    for ch in w:
        c[ord(ch)-ord('a')] += 1
    ans = f[len(w)]
    for n in c:
        ans = (ans*fi[n])%MOD
    return ans

class Solution:
    def countAnagrams(self, s: str) -> int:
        a = list(s.split())
        ans = 1
        for w in a:
            ans = (ans*ana(w))%MOD
        return ans
