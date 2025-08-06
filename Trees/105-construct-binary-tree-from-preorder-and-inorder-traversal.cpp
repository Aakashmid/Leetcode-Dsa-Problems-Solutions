
/* approach 1 ( brute force , DFS )  
main logic is that for first element of preorder , left subtree will be inorder arrays left partition(from that root in inorder) and other will be right subtree values ( right partition of inorder)

time complexity - O(n^2) 
space complexity  - O(n) 

*/
//  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(inorder.size() ==0 || preorder.size()==0)
//             return nullptr;
//         TreeNode* root = new TreeNode(preorder[0]);
//         auto it = find(inorder.begin(),inorder.end(),preorder[0]);
//         int mid = it-inorder.begin();

//         vector<int> leftPre(preorder.begin()+1,preorder.begin()+mid+1);

//         vector<int> leftIno(inorder.begin(),inorder.begin()+mid);

//         vector<int> rightPre(preorder.begin()+mid+1,preorder.end());

//         vector<int> rightIno(inorder.begin()+mid+1,inorder.end());

//         root->left = buildTree(leftPre,leftIno);
//         root->right = buildTree(rightPre,rightIno);

//         return root;

//     }

/*
Optimal DFS solution  
- Time complexity:  O(n)
- Space complexity:
O(n) for recursion stack.


## Approach Explanation 
 - Two indices (preIdx for preorder, inIdx for inorder) track the current position in each traversal.
 - The recursive dfs function builds the tree:
 - The current preorder value is always the root of the current subtree.
 - The stop parameter marks the boundary in the inorder array where the current subtree ends.
 - When the inorder value matches stop, the function returns, signaling the end of the current subtree.
 - The function recursively builds the left subtree (with the root’s value as the new stop) and then the right subtree (with the previous stop).
 - This approach processes each node exactly once, achieving O(n) time complexity.
*/

class Solution {
public:
    int preIdx =0,inIdx=0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return dfs(preorder,inorder,INT_MAX);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder ,int stop ) // here stop is value in inorder list when stop process for one side tree
    {
        // stop condition for right subtree
        if(preIdx >=preorder.size()){
            return nullptr;
        }


        // stop condition for left subtree
        if(inorder[inIdx] == stop){
            inIdx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIdx++]);
        root->left = dfs(preorder,inorder, root->val);
        root->right = dfs(preorder,inorder,stop);
        return root;
    }

};
