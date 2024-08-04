#include<bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    if(position == 0){
        newNode->next = llist;
        return newNode;
    }
    SinglyLinkedListNode* t = llist;
    for(int i=0; i<position-1; i++)
        t = t->next;
    newNode->next = t->next;
    t->next = newNode;
    return llist;
}
