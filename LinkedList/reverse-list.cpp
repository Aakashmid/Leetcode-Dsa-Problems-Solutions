#include <iostream>
#include "LinkedList.h" // custom header file for linked list creation and printing in main function
using namespace std;

/*
Approach: Reverse the linked list by iterating through it and changing the next pointers
1. Initialize a new head pointer to nullptr.
2. Iterate through the original list.
3. For each node, create a new node with the same value.
4. Insert the new node at the beginning of the new list.
5. Return the new head pointer.
Time Complexity: O(n), where n is the number of nodes in the list.
*/
ListNode *reverseList(ListNode *head)
{
    ListNode *result_head = nullptr;
    while (head)
    {
        ListNode *p = new ListNode(head->val);
        if (!result_head)
        {
            result_head = p;
        }
        else
        { // adding new element to at the start
            p->next = result_head;
            result_head = p;
        }
        // result_head = result_head->next;
        head = head->next;
    }
    return result_head;
}

int main()
{
    ListNode *head = createList({1, 2, 3, 4, 5});
    head = reverseList(head);
    cout << "After reversing: ";
    // // printList(head);

    // ListNode* head2 = head;
    // cout<<head->val<<endl;
    // cout<<head2->val;
    return 0;
}