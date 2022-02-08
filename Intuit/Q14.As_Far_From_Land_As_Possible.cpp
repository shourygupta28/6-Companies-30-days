class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size(), dist = -1;

        queue<pair<int, int>> q;

        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        if (q.size() == 0 || q.size() == m * n)
            return -1;

        while (!q.empty())
        {
            int size = q.size();
            dist++;

            while (size--)
            {
                pair<int, int> land = q.front();
                q.pop();

                int x0 = land.first;
                int y0 = land.second;

                for (int i = 0; i < 4; i++)
                {
                    int x1 = x0 + x[i];
                    int y1 = y0 + y[i];

                    if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && grid[x1][y1] == 0)
                    {
                        q.push({x1, y1});

                        grid[x1][y1] = 1;
                    }
                }
            }
        }
        return dist;
    }
};