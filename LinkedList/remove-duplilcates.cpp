#include<iostream>
#include"LinkedList.h" // custom header file for linked list createtion and printing in main function
using namespace std;


// main algorithm for removing duplicates from sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy =head;
    while(dummy){
        // delete all next node which is equal to the current node 
        while(dummy->next && dummy->next->val == dummy->val){
            ListNode* temp = dummy->next ;
            dummy->next = temp->next;
            delete temp;
        }

        dummy = dummy->next;
    }   
    return head;
}


int main(){
    ListNode* head = createList({1,1,2,3,3});
    cout<<"Before removing duplicates: ";
    printList(head);
    head = deleteDuplicates(head);
    cout<<"After removing duplicates: ";
    printList(head);
    return 0;
}