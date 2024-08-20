from collections import deque
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        ans = image
        n = len(image)
        m = len(image[0])
        init = image[sr][sc]
        q = deque()
        if init != color:
            q.appendleft((sr, sc))
        while(q):
            pt = q.pop()
            ans[pt[0]][pt[1]] = color
            if pt[0]>0 and ans[pt[0]-1][pt[1]] == init:
                q.appendleft((pt[0]-1, pt[1]))
            if pt[0]<n-1 and ans[pt[0]+1][pt[1]] == init:
                q.appendleft((pt[0]+1, pt[1]))
            if pt[1]>0 and ans[pt[0]][pt[1]-1] == init:
                q.appendleft((pt[0], pt[1]-1))
            if pt[1]<m-1 and ans[pt[0]][pt[1]+1] == init:
                q.appendleft((pt[0], pt[1]+1))
        return ans
