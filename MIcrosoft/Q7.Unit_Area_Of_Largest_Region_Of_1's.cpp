class Solution
{
public:
    void region(vector<vector<int>> &grid, int m, int n, int i, int j, int &area)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        area++;

        region(grid, m, n, i, j - 1, area);
        region(grid, m, n, i, j + 1, area);
        region(grid, m, n, i - 1, j, area);
        region(grid, m, n, i + 1, j, area);

        region(grid, m, n, i - 1, j - 1, area);
        region(grid, m, n, i - 1, j + 1, area);
        region(grid, m, n, i + 1, j - 1, area);
        region(grid, m, n, i + 1, j + 1, area);
    }

    int findMaxArea(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size(), max_area = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    region(grid, m, n, i, j, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};