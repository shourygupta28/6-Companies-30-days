class Solution
{
public:
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[i] = true;

        for (int j = 0; j < isConnected.size(); j++)
        {
            if (i != j && !visited[j] && isConnected[i][j] == 1)
            {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();
        vector<bool> visited(n, false);
        int connected_components = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                connected_components++;
            }
        }
        return connected_components;
    }
};