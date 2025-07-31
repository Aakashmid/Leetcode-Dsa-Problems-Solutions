/*

Problem Statement : check whether is binary tree symmetric or not

Recursive Approach:
   - Recursively swap the left and right children of each node.
   - Base case: If the node is null, return null.
   - Time Complexity: O(N), where N is the number of nodes (each node is visited once).
   - Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

*/

// DFS recursive approach
bool isEqual(TreeNode *left, TreeNode *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    return (left->val == right->val) && isEqual(left->left, right->right) && isEqual(left->right, right->left);
}


bool isSymmetric(TreeNode *root)
{
    return isEqual(root->left, root->right);
}


