from collections import deque

class Solution:
    
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        id = [0]*V
        for u in adj:
            for v in u:
                id[v] += 1
        q = deque()
        for i in range(V):
            if id[i] == 0:
                q.appendleft(i)
        ans = []
        while q:
            ans.append(q[-1])
            for v in adj[q[-1]]:
                id[v] -= 1
                if id[v] == 0:
                    q.appendleft(v)
            q.pop()
        return ans


#{ 
 # Driver Code Starts
# Driver Program

import sys
sys.setrecursionlimit(10**6)
        
def check(graph, N, res):
    if N!=len(res):
        return False
    map=[0]*N
    for i in range(N):
        map[res[i]]=i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        e,N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]
        
        for i in range(e):
            u,v=map(int,input().split())
            adj[u].append(v)
            
        ob = Solution()
        
        res = ob.topoSort(N, adj)
        
        if check(adj, N, res):
            print(1)
        else:
            print(0)
# Contributed By: Harshit Sidhwa

# } Driver Code Ends