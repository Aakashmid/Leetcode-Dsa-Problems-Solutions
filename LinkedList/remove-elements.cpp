#include <iostream>
#include "LinkedList.h" // custom header file for linked list creation and printing in main function
using namespace std;


// remove all node of value val
ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode dummy = ListNode();
    ListNode *tail = &dummy;
    ListNode *p = head;
    while (p)
    {
        if (p->val != val)  // add those nodes to tail dont have value val 
        {
            tail->next = p;
            tail = tail->next;
        }
        p = p->next;
    }

    tail->next = nullptr;  // handle edge case when last node has value val so tail->next should be null

    return dummy.next;
}


int main(){
    ListNode *head = createList({1, 2, 6, 3, 4, 5, 6});
    cout << "Before removing elements: ";
    printList(head);
    head = removeElements(head, 6);
    cout << "After removing elements: ";
    printList(head);
    return 0;
}