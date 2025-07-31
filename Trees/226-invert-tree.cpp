/*
Problem Statement:
------------------
Given the root of a binary tree, invert the tree, i.e., swap every left child with its right child.

Approaches:
-----------
1. Recursive Approach:
   - Recursively swap the left and right children of each node.
   - Base case: If the node is null, return null.
   - Time Complexity: O(N), where N is the number of nodes (each node is visited once).
   - Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

2. Iterative Approach (DFS using Stack):
   - Use a stack to perform DFS traversal.
   - For each node, swap its left and right children, then push non-null children onto the stack.
   - Time Complexity: O(N), where N is the number of nodes.
   - Space Complexity: O(H), where H is the height of the tree (stack size in the worst case).

The code below implements the iterative approach.
*/

TreeNode *invertTree(TreeNode *root)
{
    // if(!root || (!root->left && !root->right) )
    //     return root;
    // else{
    //     TreeNode* temp = root->left;
    //     root->left=invertTree(root->right);
    //     root->right=invertTree(temp);
    // }

    // return root;

    // iterative DFS
    if (!root)
        return root;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        TreeNode *temp = node->right;
        node->right = node->left;
        node->left = temp;

        if (node->left)
            st.push(node->left);
        if (node->right)
            st.push(node->right);
    }

    return root;
}