def mods(a, b):
    while len(a) >= len(b) and a[:len(b)] == b:
        a = a[len(b):]
    return a

def f_gcd(a, b):
    if b == '':
        return a
    md = mods(a, b)
    if len(md) >= len(b):
        return ''
    return f_gcd(b, md)

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if(len(str1) > len(str2)):
            return f_gcd(str1, str2)
        return f_gcd(str2, str1)