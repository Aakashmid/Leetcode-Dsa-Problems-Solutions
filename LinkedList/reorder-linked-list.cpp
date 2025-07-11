#include<iostream>
#include "LinkedList.h"
using namespace std;

void reorderList(ListNode* head) {

        /*
        Approach - 1 - reverse second half 
            2 - merge first and reversed second half
        */
        if (head->next && head->next->next) {

            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* slow_prev = head;

            // find middle node position
            while (fast && fast->next) {
                fast = fast->next->next;
                slow_prev = slow;
                slow = slow->next;
            }

            slow_prev->next = nullptr; //  slow_prve is last node of first list
                                       // slow  is mid

            // -------------- reverse second half list
            ListNode* l2_head = slow; // head of second half reversed list
            ListNode* p = slow->next;
            l2_head->next = nullptr;

            while (p) {
                ListNode* temp = p->next; // temp for next p pointer
                p->next = l2_head;
                l2_head = p;
                p = temp;
            }

            ListNode* l1_head = head; // list1 head pointer

            // ----------- merge list1 and list2
            while (l1_head) {
                if (!l1_head->next) {
                    l1_head->next = l2_head;
                    break;
                } else {
                    ListNode* temp1 = l1_head->next;
                    ListNode* temp2 = l2_head->next;
                    l2_head->next = temp1;
                    l1_head->next = l2_head;
                    l1_head = temp1;
                    l2_head = temp2;
                }
            }
        }
    }


// int main(){
//        ListNode* head = createList({})
// }