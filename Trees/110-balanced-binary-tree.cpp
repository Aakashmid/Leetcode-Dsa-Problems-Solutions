class Solution
{
public:
    // brute force approach  (time complexity - O(n^2)  , space complexity - O(n))
    // int maxDepth(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }

    // bool isBalanced(TreeNode* root) {
    //     if (!root)
    //         return true;

    //     if (abs(maxDepth(root->left) - maxDepth(root->right)) < 2) {
    //         return isBalanced(root->left) && isBalanced(root->right);

    //     } else
    //         return false;
    // }

    // optimal approach  ( time complexity - O(n) , space complexity - O(h) )

    /*
    Approach Explanation - 

     */
    pair<bool, int> dfs(TreeNode *root)
    { // return both height of node and wether it is balanced or not
        if (!root)
            return {true, 0};

        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);
        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;

        return {balanced, 1 + max(left.second, right.second)};
    }

    bool isBalanced(TreeNode *root)
    {
        return dfs(root).first;
    }
};