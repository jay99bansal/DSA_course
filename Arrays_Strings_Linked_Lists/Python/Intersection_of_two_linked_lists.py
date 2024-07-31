from typing import Optional

#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        """
        Two pointer approach.

        Intuition : 
            1. We will try to get the head of the starting node of each
        list in same starting point before there is a intersection, 
        as after intersection both the linked list would be of similar size.
            How ? 
            - By switching heads when reaching the end of a list, 
            both pointers will travel the same total distance, 
            which is the sum of the lengths of both lists.

            2. Then compare the each pointer of headA and headB. If intersects 
            we will return the result , if not it will reach end and return NULL.
        
        Time Complexity : O( n + m) + O(n + m) = O(n + m)
         - 1st O(n + m) For getting to end of list.
         - 2nd o(n + m) After the pointers are set to check if matches.

        Space Complexity : 0(1) , for pointers.


        """
        
        p1, p2 = headA, headB

        while p1 != p2:
            print("P1:",p1,"\n P2:",p2)
            if p1:
                p1 = p1.next
            else:
                print("switch head 1")
                p1 = headB
                

            if p2:
                p2 = p2.next
            else:
                print("switch head 2")
                p2 = headA
                
        return p1
    

# if __name__ == "__main__":
#     listA = [2,6,4] 
#     listB = [1,5]

    