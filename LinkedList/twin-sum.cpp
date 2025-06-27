#include "LinkedList.h"
#include <vector>
#include <algorithm>
using namespace std;

int pairSum(ListNode *head)
{
    vector<int> sums;
    ListNode *slow = head;
    ListNode *fast = head;

    //  go till the half and add node val to sums vector
    while (fast && fast->next)
    {
        sums.push_back(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    int n = sums.size(); // twins numbers , half of size of linked list
    int max_twin = 0;
    for (int i = 0; i < n; i++)
    {
        if (!slow)
            break;
        sums[n - 1 - i] += slow->val; // adding twins
        max_twin = max(sums[n - 1 - i], max_twin);
        slow = slow->next;
    }

    return max_twin;


    // approach 2 
    /*
    add all node values to vector and then add i with n-1-i and find max among these sums 
    */
}
int main()
{
    ListNode *head = createList({5, 4, 2, 1, 3, 1});
    int result = pairSum(head);
    cout << "Maximum twin sum: " << result << endl;
    return 0;
}