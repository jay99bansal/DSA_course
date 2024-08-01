def solve():
    n = int(input())
    if n == 1:
        print('no')
        return
    if n == 2:
        print('yes')
        return
    i = 2
    while i*i <= n:
        if n%i == 0:
            print('no')
            return
        i += 1
    print('yes')
    
t = 1
t = int(input())
for i in range(t):
    solve()