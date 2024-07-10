def solve(i):
    l,r = map(int, input().split())
    if r < 2*l:
        print('-1 -1')
    else:
        print(f'{l} {2*l}')
    

t = int(input())
for i in range(1, t+1):
    solve(i)
