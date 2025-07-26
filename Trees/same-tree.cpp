/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    /*
     */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if ((!p || !q) || (p && q && (p->val != q->val)))
        {
            return false;
        }

        bool left_st = isSameTree(p->left, q->left);
        bool right_st = isSameTree(p->right, q->right);

        // if left or right subtree is  equal
        return left_st && right_st;
    }

    // BFS solution
    //  bool isSameTree(TreeNode* p, TreeNode* q) {
    //     queue<TreeNode*> q1;
    //     queue<TreeNode*> q2;
    //     q1.push(p);
    //     q2.push(q);

    //     while (!q1.empty() && !q2.empty()) {
    //         for (int i = q1.size(); i > 0; i--) {
    //             TreeNode* nodeP = q1.front(); q1.pop();
    //             TreeNode* nodeQ = q2.front(); q2.pop();

    //             if (!nodeP && !nodeQ) continue;
    //             if (!nodeP || !nodeQ || nodeP->val != nodeQ->val)
    //                 return false;

    //             q1.push(nodeP->left);
    //             q1.push(nodeP->right);
    //             q2.push(nodeQ->left);
    //             q2.push(nodeQ->right);
    //         }
    //     }

    //     return true;
    // }

    // (DFS - go deep first in on subtree and then the other subtree)
    // DFS iterative  solution
    //     bool isSameTree(TreeNode* p, TreeNode* q) {
    //     stack<pair<TreeNode*, TreeNode*>> stk;
    //     stk.push({p, q});

    //     while (!stk.empty()) {
    //         auto [node1, node2] = stk.top();
    //         stk.pop();

    //         if (!node1 && !node2) continue;
    //         if (!node1 || !node2 || node1->val != node2->val) return false;

    //         stk.push({node1->right, node2->right});
    //         stk.push({node1->left, node2->left});
    //     }

    //     return true;
    // }
};