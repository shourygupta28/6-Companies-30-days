class Solution
{
public:
    void dfsOcean(int i, int j, int prev, vector<vector<int>> &heights, vector<vector<bool>> &ocean)
    {
        int m = heights.size(), n = heights[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || prev > heights[i][j])
            return;

        if (ocean[i][j] == true)
            return;

        ocean[i][j] = true;

        dfsOcean(i + 1, j, heights[i][j], heights, ocean);
        dfsOcean(i - 1, j, heights[i][j], heights, ocean);
        dfsOcean(i, j + 1, heights[i][j], heights, ocean);
        dfsOcean(i, j - 1, heights[i][j], heights, ocean);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfsOcean(i, 0, heights[i][0], heights, pacific);
            dfsOcean(i, n - 1, heights[i][n - 1], heights, atlantic);
        }

        for (int j = 0; j < n; j++)
        {
            dfsOcean(0, j, heights[0][j], heights, pacific);
            dfsOcean(m - 1, j, heights[m - 1][j], heights, atlantic);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};