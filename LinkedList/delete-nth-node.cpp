#include <iostream>
#include "LinkedList.h" // custom header file for linked list creation and printing in main function
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // two pointer approach
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n; i++)
    { // first move fast pointer n steps ahead so that when fast reaches end slow will be at the node to delete
        fast = fast->next;
    }

    if (!fast)
    { // when first remove the first element (edge case)
        return head->next;
    }
    while (fast->next) // until fast pointer reaches the end of list
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;


    // ------------------------------------------------------------------
    // ------------------------------------------------------------------
    // brute force approach  ( by calculating size of linked list)
    // ListNode* p = head;
    // // caculating size of linked list
    // int size = 0;
    // while (p) {
    //     p = p->next;
    //     size++;
    // }

    // // for first element to remove (edge case)
    // if(size-n==0){
    //     if(head->next){
    //         ListNode* temp =head;
    //         head = head->next;
    //         delete temp;
    //         return head;
    //     }
    //     else{
    //         return nullptr;
    //     }
    // }

    // p = head;
    // int count = 0;
    // while (p) {
    //     if (count == size-n-1 && p->next) {
    //         if (count == size - 2) {  // if has to delete last node ;
    //             p->next = nullptr;
    //         }
    //         else {
    //             ListNode* temp = p->next; // get node to delete
    //             p->next = temp->next;
    //             delete temp; // delete node temp
    //         }
    //         break;
    //     }
    //     count++;
    //     p = p->next;
    // }
    // return head;
}

int main()
{
    ListNode *head = createList({1, 2, 3, 4, 5});
    printList(head);
    head = removeNthFromEnd(head, 2);
    printList(head);
    return 0;
}