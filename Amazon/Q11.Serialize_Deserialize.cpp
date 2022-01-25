// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
public:
    void serializeHelper(Node *root, vector<int> &preorder)
    {
        if (root == NULL)
        {
            preorder.push_back(int(NULL));
            return;
        }

        preorder.push_back(root->data);
        serializeHelper(root->left, preorder);
        serializeHelper(root->right, preorder);
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        //Your code here
        vector<int> preorder;
        serializeHelper(root, preorder);
        return preorder;
    }

    Node *deserializeHelper(vector<int> &A, int &i)
    {
        // if i has gone out of array
        if (i == A.size())
            return NULL;

        //null node
        if (A[i] == int(NULL))
        {
            i++;
            return NULL;
        }

        Node *root = new Node(A[i]);
        i++;
        root->left = deserializeHelper(A, i);
        root->right = deserializeHelper(A, i);

        return root;
    }
    //Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        //Your code here
        int i = 0;
        return deserializeHelper(A, i);
    }
};