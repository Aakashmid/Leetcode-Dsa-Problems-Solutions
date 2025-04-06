// header file for linked list structure and function ( for reusability )
#ifndef LINKED_LIST_UTILS_H
#define LINKED_LIST_UTILS_H

#include <iostream>
#include <initializer_list>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Create a linked list from an initializer list, e.g., {1, 2, 3}
inline ListNode* createList(initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : values) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

// Print the linked list
inline void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


#endif // LINKED_LIST_UTILS_H
