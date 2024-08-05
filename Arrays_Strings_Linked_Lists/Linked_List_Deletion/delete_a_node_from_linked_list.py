def deleteNode(llist, position):
    """
    Time Complexity : O(N)
    """
    index = 0
    head = llist

    if index == position:
        return head.next
    else:
        while head:
            if index == position - 1:
                head.next = head.next.next
                break
            index += 1
            head = head.next

    return llist


