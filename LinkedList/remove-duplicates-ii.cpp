#include<iostream>
#include"LinkedList.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {

    // approach 1
     // Dummy node before the actual head to handle edge cases easily
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* current = head;

    while (current) {
        // If it's a beginning of duplicates sequence
        if (current->next && current->val == current->next->val) {
            // Skip all nodes with the same value
            while (current->next && current->val == current->next->val) {
                current = current->next;
            }
            // Connect prev to the next distinct node
            prev->next = current->next;
        } else {
            // No duplicates, move prev forward
            prev = prev->next;
        }
        current = current->next;
    }

    return dummy->next;

    

    // approach  2
    // if(!head || !head->next){ // return head if 1 or 0 node present
    //     return head;
    // }

    // ListNode* prev = head;
    // ListNode* curr = head->next;
    // while (curr) {
    //     bool IsDuplicate = false;
    //     while (curr->next && curr->next->val == curr->val) {
    //         ListNode* temp = curr->next;
    //         curr->next = temp->next;
    //         delete temp;
    //         IsDuplicate = true;
    //     }

    //     // two case for deleting curr node , 1 - when prev is also its
    //     duplicate and 2 - when only curr is left in its duplicates
    //     if(prev->val == curr->val && curr!=prev){  //
    //         if (prev == head) { // if deleting node is head
    //             head = curr->next;
    //         }
    //         ListNode* temp = curr;
    //         ListNode* temp2 = prev;
    //         prev = temp->next;
    //         curr = temp->next ? temp->next->next:nullptr;
    //         delete temp;
    //         delete temp2;
    //     }
    //     else if (IsDuplicate) { // when curr node had duplicate then
    //     delete curr also
    //         ListNode* temp = curr;
    //         prev->next = temp->next;
    //         curr = temp->next;
    //         delete temp;
    //     }
    //     else { // just move the pointers
    //         prev= prev->next;
    //         curr = curr->next;
    //     }
    // }
    // return head;
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