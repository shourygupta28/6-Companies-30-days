/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
               // base case
        if(head==NULL)
            return;
        
        Node* curr= head;
        
        while(curr)  
        {
            int count=1;
            while(curr!=NULL && count<M)
            {
                curr= curr->next;
                count++;
            }
            
            if(curr==NULL)
                return;
            
            Node* temp= curr->next;
            count= 0;
            
            while( temp!=NULL && count<N)
            {
                Node *node= temp;
                temp= temp->next;
                free(node);
                count++;
            }
            
            curr->next= temp;
            
            curr= curr->next;
            
        }
    }
};
