/*
node structure 
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *next) : val(x), left(left), right(right), next(next) {}
}
*/



Node *connect(Node *root)
{
    if (!root)
        return root;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        for (int i = q.size(); i > 0; i--)
        {
            Node *n1 = q.front();
            q.pop();
            if (i > 1)
            {
                n1->next = q.front();
            }
            else
            {
                n1->next = nullptr;
            }

            if (n1->left)
            {
                q.push(n1->left);
                q.push(n1->right);
            }
        }
    }
    return root;
}