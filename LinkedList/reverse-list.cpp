#include <iostream>
#include "LinkedList.h"  // custom header file for linked list creation and printing in main function
using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode* result_head = nullptr;
    while (head) {
        ListNode* p = new ListNode(head->val);
        if (!result_head) {
            result_head = p;
        } else { // adding new element to at the start 
            p->next = result_head;
            result_head = p;
        }
        // result_head = result_head->next;
        head = head->next;
    }
    return result_head;
}


int main() {
    ListNode* head = createList({1, 2, 3, 4, 5});
 
    head = reverseList(head);
    cout << "After reversing: ";
    printList(head);
    return 0;
}