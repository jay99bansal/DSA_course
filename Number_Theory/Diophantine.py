def f_gcd(a, b):
    # Returns x, y, g
    if b==0:
        return 1, 0, a
    x0, y0, g = f_gcd(b, a%b)
    return y0, x0-(a//b)*y0, g

def solve(i):
    a,b,c = map(int, input().split())
    if a>b:
        x,y,g = f_gcd(a,b)
    else:
        y,x,g = f_gcd(b,a)
    if c%g == 0:
        # print(f'Case {i}: x = {(c//g)*x}, y = {(c//g)*y}')
        x1 = (c//g)*x
        y1 = (c//g)*y
        llmit = -x1//(b//g)+1
        ulimit = y1//(a//g)
        if y1%(a//g) == 0:
            ulimit -= 1
        print(ulimit-llmit+1)
        for k in range(llmit, ulimit+1):
            print(f'{x1+b//g*k} {y1-a//g*k}')
    else:
        print(0)

t = int(input())
for i in range(1, t+1):
    solve(i)