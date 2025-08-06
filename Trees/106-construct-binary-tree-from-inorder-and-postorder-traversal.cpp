
/*
//// Brute force approach



explantion -

*/
// TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//     if(inorder.empty() && postorder.empty())
//         return nullptr;

//     TreeNode* root = new TreeNode(postorder.back());
//     int pos = find(inorder.begin(),inorder.end(),postorder.back()) - inorder.begin();
//     // left subtree postorder and inorder vectors
//     vector<int> leftIn(inorder.begin(),inorder.begin()+pos);
//     vector<int> leftPost(postorder.begin(),postorder.begin()+pos);

//     // right subtree postorder and inorder vector
//     vector<int> rightIn(inorder.begin()+pos+1,inorder.end());
//     vector<int> rightPost(postorder.begin()+pos,postorder.begin()+pos+rightIn.size());

//     root->left = buildTree(leftIn,leftPost);
//     root->right = buildTree(rightIn,rightPost);
//     return root;
// }






/*
// Optimal approach


## Approach Explanation
- Traverse postorder and inorder arrays from the end (right to left).
- The last element in postorder is always the current subtree’s root.
- Use a stop value to mark subtree boundaries in inorder traversal.
- Recursively build the right subtree first, then the left subtree.
- No array copying; only indices are used, making it efficient.

Time complexity: O(n), Space complexity: O(n) (recursion stack).
*/

TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int stop)
{
    if (postIdx < 0)
    {
        return nullptr;
    }

    if (inorder[inIdx] == stop)
    {
        inIdx--;
        return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[postIdx--]);
    root->right = dfs(inorder, postorder, root->val);
    root->left = dfs(inorder, postorder, stop);
    return root;
}
