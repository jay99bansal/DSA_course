import math
n = 1000
# Step 1
pr = [True for i in range(n+1)]
pr[0] = pr[1] = False
for i in range(2, int(math.sqrt(n))+1):
    if pr[i]:
        for j in range(i*i, n+1, i):
            pr[j] = False
#Step 2
prs = []
for i in range(2, n+1):
    if pr[i]:
        prs.append(i)
#Step 3
cb = [False for i in range(n+1)]
for i in range(len(prs)-1):
    ele = prs[i] + prs[i+1] + 1
    if ele > n:
        break
    if pr[ele]:
        cb[ele] = True
#Step 4
n,k = map(int, input().split())
c = 0
for i in range(2, n+1):
    if cb[i]:
        c += 1
if c >= k:
    print('YES')
else:
    print('NO')
