# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	# @param A : head node of linked list
	# @return an integer
    def lPalin(self, A):
        """
        Time Complexity: O(n + n) -> O(n)
        Space Complexity: O(n) For reverse list

        """
        
        # Return 1 , if Linked List is empty or has only 1 value.
        if not A or not A.next:
            return 1
        
        # Initialize parameters
        curr_list = A
        rev_list = None
        
        # Reverse the linked list in a new ListNode
        while curr_list:
            # store the next in new node 
            next_node = curr_list.next

            # Add the current element to the last of the reversed list
            curr_list.next = rev_list
            rev_list = curr_list

            # Move current pointer to original list
            curr_list = next_node
            
        
        # Checking is value in the original and the reserved list at same
        while A:
            # If fails , return 0
            if A.val != rev_list.val:
                return 0
            else:
                A = A.next
                rev_list = rev_list.next
        
        return 1 
            
        
