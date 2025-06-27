/*
Problem Statement:
Given a singly linked list, group all odd nodes together followed by even nodes.
The first node is considered odd, and the second node is even, and so on.
Note: The relative order inside both the even and odd groups should remain as it was in the input.

Approach:
1. Create two pointers odd and even, initialize odd to head and even to head->next
2. Store even_start to connect later
3. Connect odd nodes together and even nodes together
4. Connect odd list end to even list start
*/

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_start = head->next;

    while (odd->next && even->next)
    {
        odd->next = even->next;
        even->next = odd->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = even_start;
    return head;
}
