class Solution
{
public:
    bool isPathDFS(int c, int d, vector<int> adj[], vector<int> &vis)
    {

        if (c == d)
            return true;

        vis[c] = 1;

        for (auto it : adj[c])
            if (!vis[it])
                if (isPathDFS(it, d, adj, vis))
                    return true;
        return false;
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {

        vector<int> vis(V, 0);

        for (auto it = adj[c].begin(); it != adj[c].end();)
        {
            if (*it == d)
            {
                adj[c].erase(it);
                break;
            }
            else
                it++;
        }

        for (auto it = adj[d].begin(); it != adj[d].end();)
        {
            if (*it == c)
            {
                adj[d].erase(it);
                break;
            }
            else
                it++;
        }

        if (isPathDFS(c, d, adj, vis))
            return 0;

        return 1;
    }
};