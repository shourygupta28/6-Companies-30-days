class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>ans;
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0; i<k; i++)
        {
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        
        for(int i=k; i<n; i++)
        {
            while(!pq.empty() && pq.top().second<i-k+1)
            {
                pq.pop();
            }
            
            pq.push({arr[i],i});
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};
