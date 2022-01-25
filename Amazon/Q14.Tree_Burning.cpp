class Solution {
  public:
     int BFStoBurnTree(Node* target, map<Node*, Node*> &parents)
    {
        map< Node*, int> vis;
        queue<Node*>q;
        q.push(target);
        vis[target]=1;
        int timer=-1;
        
        while(!q.empty())
        { 
            int size= q.size();
            timer++;
            
            while(size--)
            {
                 Node *node= q.front();
                 q.pop();
                 
                 if(parents[node] && !vis[parents[node]])
                 { 
                     q.push(parents[node]);
                     vis[parents[node]]=1;
                 }
                 
                 if(node->left && !vis[node->left])
                 { 
                     q.push(node->left);
                     vis[node->left]=1;
                 }
                 
                 if(node->right && !vis[node->right])
                 { 
                     q.push(node->right);
                     vis[node->right]=1;
                 }
            }
            
        }
        return timer;
        
    }
    
    void BFStoMapParents(Node* root, map<Node*, Node*> &parents, int x, Node* &target)
    {
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* node= q.front();
            q.pop();
            
            if(node->data==x) 
                target= node;
            
            if(node->left)
                {
                    parents[node->left]= node;
                    q.push(node->left);
                }
            if(node->right)
                {
                    parents[node->right]= node;
                    q.push(node->right);
                }
        }

    }
    int minTime(Node* root, int tar) 
    {
        // Your code goes here
         if(root==NULL)
            return 0;
        
        map<Node*, Node*> parents;
        Node* target= NULL;
        BFStoMapParents(root, parents, tar, target);
        
        int min_time=0;
        if(target!=NULL)
            min_time= BFStoBurnTree(target, parents);
        
        return min_time;
        
    }
};
