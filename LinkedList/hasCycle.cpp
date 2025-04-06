#include<iostream>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/////////////////////////////////////////////// main algorithm
bool hasCycle(ListNode *head) {
    // unordered_map<ListNode*,bool> m;  // can also solve using hashmap by checking if node is already visited or not (but it is taking much time)
    ListNode* slow=head;
    ListNode* fast =head;
    while(fast && fast->next){  // if fast is null than there is no cycle because it will iterate through listnod faster than slow pointer
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}



int main(){
    // Create a linked list with cycle: 1->2->3->4->5->2 (cycle at 2)  /// creating data for testing
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;  // Creating cycle by pointing back to second node
    
    cout << "List with cycle: " << hasCycle(head) << endl;  // Should print 1 (true)
    
    // Create a linked list without cycle: 1->2->3->NULL
    ListNode* head2 = new ListNode(1);
    ListNode* second2 = new ListNode(2);
    ListNode* third2 = new ListNode(3);
    
    head2->next = second2;
    second2->next = third2;
    third2->next = NULL;
    
    cout << "List without cycle: " << hasCycle(head2) << endl;  // Should print 0 (false)
    
    return 0;
}