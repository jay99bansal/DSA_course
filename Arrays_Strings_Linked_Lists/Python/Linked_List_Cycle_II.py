# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head):
        if not head:
            return head
        s = head
        f = head
        while True:
            if f.next == None or f.next.next == None:
                return None
            s = s.next
            f = f.next.next
            if s == f:
                break
        s = head
        while s!=f:
            s = s.next
            f = f.next
        return s