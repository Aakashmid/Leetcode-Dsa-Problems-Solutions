#include<iostream>
#include"LinkedList.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if(!head){
        return NULL;
    }

    // two pointers approach 
    int len=0;
    ListNode*p = head;
    while(p){  // find length of linked list
        len++;
        p=p->next;
    }

    ListNode* slow=head;
    ListNode* fast=head;
    for(int i=0;i<k%len;i++){ // move fast ahead of slow k%len steps
        fast = fast->next;
    }

    // till fast reaches end of list move both pointers
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }


    // rotate list
    fast->next = head;
    head = slow->next;
    slow->next = nullptr;

    return head;

}

int main(){
    ListNode* head = createList({1,2,3,4,5});
    printList(head);
    head = rotateRight(head,2);
    printList(head);
    return 0;
}