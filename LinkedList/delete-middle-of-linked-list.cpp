#include<iostream>
#include"LinkedList.h" // custom header file for linked list creation and printing in main function
using namespace std;


// main program for deleting middle node in linked list
ListNode* deleteMiddle(ListNode* head) {
    // two pointer approach , whenever fast pointer reaches to the end of the list slow pointer will be at middle node
    ListNode* slow=head;
    ListNode* temp=head;
    ListNode* fast=head;

    // edge case when only one node is present 
    if(!head->next){
        return nullptr;
    }

    while(fast && fast->next){
        temp=slow;
        slow =slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    delete slow;

    return head;
}

int main(){
    ListNode* head = createList({1,2,3,4,5});
    printList(head);
    head = deleteMiddle(head);
    printList(head);
    return 0;
}