class Solution
{
public:
    int buildTree(Node *node)
    {

        if (node == NULL)
            return 0;

        int ls = buildTree(node->left);
        int rs = buildTree(node->right);

        int prev_data = node->data;
        node->data = ls + rs;
        return prev_data + ls + rs;
    }

    void toSumTree(Node *node)
    {
        int x = buildTree(node);
    }
};
