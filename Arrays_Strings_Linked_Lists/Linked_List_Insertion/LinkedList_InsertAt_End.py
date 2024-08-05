#!/bin/python3

import math
import os
import random
import re
import sys


class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None



# Complete the insertNodeAtTail function below.


#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next

def insertNodeAtTail(head, data):
    """
    Time Complexity: (n)
    Space Complexity: (1)
    """
    # add new node
    new_node = SinglyLinkedListNode(data)

    # Keep current tracker
    current = head

    # if head is null return new node
    if head is None:
        return new_node

    # move to last of the node
    while current.next:
        current = current.next
    # add new new if element exsits in new node.
    current.next = new_node

    # return head of the whole linked list
    return head


