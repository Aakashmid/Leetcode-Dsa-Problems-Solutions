
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

/////////////////////////////////////////////// main algorithm
bool hasCycle(ListNode *head)
{


    // -------------- fast slow pointer approach ( time complexity - O(n) , space complexity O(1) ) --------------
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    { // if fast is null than there is no cycle because it will iterate through listn faster than slow pointer
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;


    // -------------- hashset approach ( time complexity - O(n) , space complexity O(n) ) --------------
    
    // unordered_set<ListNode*> seen;
    // ListNode* curr = head;
    // while(curr){
    //     if(seen.find(curr)!=seen.end()){
    //         return true;
    //     }
    //     seen.insert(curr);
    //     curr = curr->next;
    // }

    // return false;
}
