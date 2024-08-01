from typing import Optional

#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        Using Fast and Slow pointer method. 
        Slow moves 1 node at a time , while fast moves 2 times in single iteration.

        Eventually if cycle is present there will be an intersection.

        Time Complexity: O(n-2 + n-2 ...) + O(n) -> O(n) 
        as it will run has fast pointer till it intersects with slow pointer.

        Space Complexity: O(1)

        """

        # Initialize pointers
        slow_p = head
        fast_p = head

        # Check fast poinert or the next of fast pointer is not Null as 
        #it move 2 places at a time.

        while fast_p and fast_p.next:
            slow_p = slow_p.next
            fast_p = fast_p.next.next

            # If intersects it will return True
            if slow_p == fast_p:
                return True

        return False
