class Solution {
public:
    bool isCycle( int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis )
    {
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto it: adj[node])
        {
            if(vis[it]==0 && isCycle(it,adj,vis,dfsVis))
                return true;
            else if(vis[it]==1 && dfsVis[it]==1)
                return true;
        }
        
        dfsVis[node]=0;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    
	    vector<int> adj[N];
	    
	   for(auto u: prerequisites)
	        adj[u.second].push_back(u.first);
	        
	    vector<int> vis(N,0);
	    vector<int> dfsVis(N,0);
	    
	    for(int i=0; i<N; i++)
	    {
	        if(vis[i]==0)
	            if(isCycle(i,adj,vis,dfsVis))
	                return false;
	    }
	    return true;
	}
};