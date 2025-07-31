/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

int maxDepth(TreeNode *root)
{
    // recursive DFS
    // if (!root)
    //     return 0;
    // return 1 + max(maxDepth(root->left), maxDepth(root->right));

    // iterative DFS -------------------------------------- 
    
    int res = 0;
    stack<pair<TreeNode *, int>> st; // pair of node and depth
    st.push({root, 1});
    while (!st.empty())
    {
        pair<TreeNode *, int> curr = st.top();
        st.pop();
        TreeNode *node = curr.first;
        if (curr.first)
        {
            res = max(res, curr.second);
            st.push({node->left, curr.second + 1});
            st.push({node->right, curr.second + 1});
        }
    }
    return res;
}