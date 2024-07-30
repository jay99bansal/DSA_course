#User function Template for python3

def calc_lps(p):
    m = len(p)
    lps = [0]
    i = 0
    j = 1
    while j < m:
        if p[i] == p[j]:
            i += 1
            lps.append(i)
            j += 1
        else:
            if i == 0:
                lps.append(0)
                j += 1
            else:
                i = lps[i-1]
    return lps

class Solution:
    def search(self, pat, txt):
        lps = calc_lps(pat)
        # print(lps)
        ans = []
        i = 0
        j = 0
        n = len(txt)
        m = len(pat)
        while i < n:
            if txt[i] == pat[j]:
                i += 1
                j += 1
                if j == m:
                    ans.append(i-m+1)
                    j = lps[j-1]
            else:
                if j == 0:
                    i += 1
                else:
                    j = lps[j-1]
        return ans
        # code here
