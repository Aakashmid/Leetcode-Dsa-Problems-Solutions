/*
Inorder Traversal :- left subtree - root - right subtree
*/

// recurrsive approach 
class Solution {
public:
    vector<int> inorder;
    void traverse(TreeNode* root){
        if(!root)
            return;
        traverse(root->left);
        inorder.push_back(root->val);                                        
        traverse(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return inorder;
    }
 
};