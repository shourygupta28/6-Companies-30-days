class Solution
{
public:
    void connect(Node *root)
    {

        queue<Node *> q;
        q.push(root);
        Node *prev;

        while (!q.empty())
        {
            int size = q.size();
            prev = NULL;

            while (size--)
            {
                Node *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                if (prev != NULL)
                    prev->nextRight = node;
                prev = node;
            }
            prev->nextRight = NULL;
        }
    }
};
