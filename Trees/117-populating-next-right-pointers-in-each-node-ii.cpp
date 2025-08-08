/*Brute force approach (BFS with queue)

time complexity - O(n) , space complexity - O(n)
*/


//   Node* connect(Node* root) {
//         if (!root)
//             return root;
//         queue<Node*> q;
//         q.push(root);
//         while (!q.empty()) {
//             for (int i = q.size(); i > 0; i--) {
//                 Node* n1 = q.front();
//                 q.pop();
//                 if (i > 1) {
//                     n1->next = q.front();
//                 } else {
//                     n1->next = nullptr;
//                 }

//                 if (n1->left) {
//                     q.push(n1->left);
//                 }
//                 if (n1->right)
//                     q.push(n1->right);
//             }
//         }
//         return root;
//     }

/*
// approach 2 ( BFS without queue)
time complexity - O(n) , space complexity - O(1)

Explanation  : -
 1. We will use two pointers head and tail to keep track of the current level of the tree.
 2. We will traverse the tree level by level and for each level, we will update the head and tail pointers.
 3. For each node, we will update the next pointer of the current node to the next node in the same level.
 4. We will update the head and tail pointers to the next level of the tree.
 5. We will continue this process until we reach the end of the tree.
 6. Finally, we will return the root of the tree.
*/

Node *connect(Node *root)
{
    if (!root)
        return root;

    Node *curr = root;
    Node *head = nullptr;
    Node *tail = nullptr; // head-  head and tail are head and tail of current level  , curr - current node

    while (curr)
    {
        if (curr->left)
        {
            if (tail)
                tail = tail->next = curr->left;
            else
                head = tail = curr->left;
        }
        if (curr->right)
        {
            if (tail)
                tail = tail->next = curr->right;
            else
                head = tail = curr->right;
        }

        curr = curr->next;
        if (!curr)
        {
            curr = head;
            head = tail = nullptr;
        }
    }

    return root;
}