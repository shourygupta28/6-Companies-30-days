class node
{
public:
    char ch;
    node *next, *prev;
    node(char _ch)
    {
        ch = _ch;
    }
};

node *head = new node('#');
node *tail = new node('#');

//constructor to initialize DLL
Solution()
{
    head->next = tail;
    tail->prev = head;
}

//function to add node just before tail
void addNode(node *newnode)
{
    node *prevnode = tail->prev;
    newnode->prev = prevnode;
    newnode->next = tail;
    prevnode->next = newnode;
    tail->prev = newnode;
}

//function to delete the node
void deleteNode(node *delnode)
{
    node *delprev = delnode->prev;
    node *delnext = delnode->next;
    delprev->next = delnext;
    delnext->prev = delprev;
}

char firstNonRepChar()
{
    return (head->next)->ch;
}

string FirstNonRepeating(string A)
{
    int n = A.length();
    string ans = "";
    vector<node *> hash(26, NULL);
    int repeated[26] = {0};

    for (int i = 0; i < n; i++)
    {
        node *u = new node(A[i]);

        //doen't exists already
        if (repeated[A[i] - 'a'] == 0)
        {
            addNode(u);
            hash[A[i] - 'a'] = u;
        }
        else
        {
            if (hash[A[i] - 'a'] != NULL)
            {
                deleteNode(hash[A[i] - 'a']);
                hash[A[i] - 'a'] = NULL;
            }
        }

        repeated[A[i] - 'a'] = 1;
        ans += firstNonRepChar();
    }

    return ans;
}
