#include<iostream>
#include"LinkedList.h"
using namespace std;

ListNode* partition(ListNode* head, int x) {

    // approach - just create two list left and right , store smaller elements than x and others in right and then add both and return left list head

    // ListNode* left = new ListNode(0);
    // ListNode* right = new ListNode(0);
    // ListNode* ltail=left;
    // ListNode* rtail =right;
    // while(head){
    //     if(head->val<x){
    //         ltail->next = head;
    //         ltail = ltail->next;
    //     }
    //     else{
    //         rtail->next = head;
    //         rtail = rtail->next;
    //     }
    //     head = head->next;
    // }
    // ltail->next=right->next;
    // rtail->next = NULL;

    // return left->next;




//  approach 2  (move prev pointer till first >=x value found after that add all smaller value to that as tail and update tail )
    if (!head) return head;

    // Dummy node ahead of real head
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;       // will point to node before first ≥ x

    // Advance prev until prev->next is the first node ≥ x
    while (prev->next && prev->next->val < x) {
        prev = prev->next;
    }

    // curr scans through the remainder of the list
    ListNode* curr = prev->next;
    while (curr && curr->next) {
        if (curr->next->val < x) {
            // Extract node < x
            ListNode* tmp = curr->next;
            curr->next    = tmp->next;

            // Splice it right after prev
            tmp->next     = prev->next;
            prev->next    = tmp;

            // Advance prev to include the newly spliced node
            prev = tmp;
        } else {
            // Node ≥ x — keep scanning
            curr = curr->next;
        }
    }

   
    return dummy.next;

}


int main(){
    ListNode* head = createList({1,4,3,2,5,2});
    printList(head);
    head = partition(head,3);
    printList(head);
    return 0;
}