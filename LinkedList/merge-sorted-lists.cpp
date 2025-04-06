#include<iostream>
#include"LinkedList.h"  // custom header file for linked list createtion and printing in main function
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


    // optimized approach
    ListNode ans;
    ListNode* tail = &ans;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) {
        tail->next = list1;
    } else if (list2) {
        tail->next = list2;
    }

    return ans.next;



// approach , brute force  2 (not optimized )
    // ListNode* ans = nullptr;
    // ListNode* temp = ans; // this is for storing node of
    // ListNode* temp_l1 = list1;
    // ListNode* temp_l2 = list2;

    // // first go through l1 add values of l1 to ans linnked list
    // while (temp_l1) {
    //     if (!temp) {
    //         temp = new ListNode(temp_l1->val);
    //         ans = temp;
    //     } else {
    //         temp->next = new ListNode(temp_l1->val);
    //         temp = temp->next;
    //     }
    //     temp_l1 = temp_l1->next;
    // }

    // // iterate through second list
    // temp = ans;
    // while (temp_l2) {
    //     int count = 0;
    //     if (!temp) {
    //         temp = new ListNode(temp_l2->val);
    //         ans = temp;
    //     } else {
    //         while (temp->next && temp->next->val < temp_l2->val) { //
    //         move temp while next element of ans is greater than l2 node
    //         value
    //             temp = temp->next;
    //         }
    //         if (temp_l2->val < temp->val &&
    //             count == 0) { // edge case when first element of ls1 is
    //                           // greater than first node of l2
    //             temp = new ListNode(temp_l2->val);
    //             temp->next = ans;
    //             ans = temp;
    //         } else {
    //             ListNode* temp_prev_next = temp->next;
    //             temp->next = new ListNode(temp_l2->val);
    //             temp = temp->next;
    //             temp->next = temp_prev_next;
    //         }
    //     }
    //     temp_l2 = temp_l2->next;
    // }
    // return ans;
}


int main(){
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});
    ListNode* mergedList = mergeTwoLists(list1, list2);
    printList(mergedList); // Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4
    return 0;
}