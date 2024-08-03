class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        n = len(s)
        for i in range(n):
            flag = True
            for j in range(n):
                if s[(i+j)%n] != goal[j]:
                    flag = False
                    break
            if flag:
                break
        return flag