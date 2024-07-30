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

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *p1 = head1, *p2 = head2;
    while(p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
        if(p1 == NULL)
            p1 = head2;
        if(p2 == NULL)
            p2 = head1;
    }
    return p1->data;
}
