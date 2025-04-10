#include <iostream>
#include "LinkedList.h"  // custom header file for linked list creation and printing in main function
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* result_head = nullptr;
    ListNode* rev_head = result_head; // reverse part head pointer
    ListNode* rev_tail = result_head; // reverse part tail pointer
    ListNode* tail =
        result_head; // tail pointer for list before reversing part
    int index = 1;

    // if left and right index are equal return list as it is
    if (left == right) {
        return head;
    }

    while (head) {
        // for first node 
        if (!result_head) {
            result_head = new ListNode(head->val);
            rev_head = result_head;
            tail = result_head;
            rev_tail = tail;
        } else if (index == left) { 
            rev_head->next = new ListNode(head->val);
            rev_head = rev_head->next;
            tail->next = rev_head;
            rev_tail = rev_head;
        }
        // change rev_head and assign it to tail part of non reverse
         else if (index > left && index <= right) {
            ListNode* p = new ListNode(head->val);
            if (left != 1) {
                tail->next = p;
                p->next = rev_head;
                rev_head = p;
            } else { // when left is 1 assing first reverse node address to result node 
                p->next = rev_head;
                rev_head = p;
                result_head = p;
            }
        } 
        // until index is not reached to left value
        else {
            tail->next = new ListNode(head->val);
            tail = tail->next;
            rev_head = tail;
            rev_tail = tail;
        }

        index++;
        head = head->next; // move pointer to current node

        if (index > right) {
            break;
        }
    }

// when index is greater than right , just add head to rev_tail
    if (head) {
        rev_tail->next = head;
    }

    return result_head;
}

int main(){
    ListNode* head = createList({1, 2, 3, 4, 5});
    head = reverseBetween(head, 2, 4);
    cout << "After reversing: ";
    printList(head);
    return 0;
}