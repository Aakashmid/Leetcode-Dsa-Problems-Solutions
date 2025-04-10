#include <iostream>
#include "LinkedList.h" // custom header file for linked list creation and printing in main function
using namespace std;

// Approach: Iterate through both lists simultaneously, adding digits and maintaining carry
// Create new nodes for sum % 10 and carry digit (sum/10) for next iteration
// Handle cases where lists have different lengths and remaining carry
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode res;
    ListNode *p = &res;
    int carry = 0, sum = 0;

    // add number of both list until they have same number of digits
    while (l1 && l2)
    {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    // add digits if any list is smaller to other
    while (l1)
    {
        sum = l1->val + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10); // add new node to tail and then move pointer to new tail
        p = p->next;
        l1 = l1->next;
    }
    while (l2)
    {
        sum = l2->val + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l2 = l2->next;
    }
    if (carry > 0)
    {
        p->next = new ListNode(carry);
        p = p->next;
    }

    return res.next;
}

int main()
{
    ListNode *l1 = createList({2, 4, 3});
    ListNode *l2 = createList({5, 6, 4});
    ListNode *ans = addTwoNumbers(l1, l2);
    printList(ans);
    return 0;
}