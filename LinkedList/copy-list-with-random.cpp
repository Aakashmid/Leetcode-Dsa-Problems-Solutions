#include <iostream>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




// function to copy linked list with random pointer , using hash map, node in copy list not point to node of original list
// time complexity : O(n) , space complexity : O(n)
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> old_to_copy; // contains map from old node to new node ;
    Node *curr = head;
    while (curr)
    {
        Node *copy = new Node(curr->val);
        old_to_copy[curr] = copy;
        curr = curr->next;
    }

    curr = head;
    while (curr)
    {
        Node *copy = old_to_copy[curr];
        copy->next = old_to_copy[curr->next];
        copy->random = old_to_copy[curr->random];
        curr = curr->next;
    }

    return old_to_copy[head];
}
