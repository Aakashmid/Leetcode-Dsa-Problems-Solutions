
#include "LinkedList.h" // custom header file for linked list creation and printing in main function
#include <iostream>
using namespace std;

// Find the mid using fast pointer and slow pointer approach = O(N/2) ->
// O(N). Reverse the first half of the list inline = O(N/2) -> O(N) time,
// O(1) space. Compare the 2 lists. = O(N) time, O(1) space.
bool isPalindrome(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    //  get the middle pointer position
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //  create new list for end  half list which is reveresed
    ListNode *newList = nullptr; // end half list
    while (slow)
    {
        ListNode *temp = slow->next;
        slow->next = newList;
        newList = slow;
        slow = temp; // move slow
    }

    fast = head;
    // campare reversed list and second half list
    while (newList && fast)
    {
        if (fast->val != newList->val)
        {
            return false;
        }
        newList = newList->next;
        fast = fast->next;
    }
    return true;

    // approach 2 (brute force approach)
    /*
    create reversed version of list and compare both
    */
    //  create reversed list
    // ListNode * curr = head;
    // ListNode* newList = nullptr;
    // while(curr){
    //     ListNode* temp = new ListNode(curr->val);
    //     if(!newList){
    //         newList = temp;
    //     }
    //     else{
    //         temp->next = newList;
    //         newList = temp;
    //     }
    //     curr = curr->next;
    // }

    // // compare both list
    // while(newList && head){
    //     if(newList->val!=head->val){
    //         return false;
    //     }
    //     newList = newList->next;
    //     head = head->next;
    // }
    // return true;
}

int main()
{
    ListNode *head = createList({1, 2, 3, 4, 5});
    cout << "Is palindrome: " << isPalindrome(head) << endl;

    return 0;

}