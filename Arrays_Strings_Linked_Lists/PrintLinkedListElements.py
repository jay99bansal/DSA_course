class Solution:
    # Function to display the elements of a linked list
    def display(self, head):
        #code here
        t = head
        while t:
            print(t.data, end=' ')
            t = t.next
        print('')
