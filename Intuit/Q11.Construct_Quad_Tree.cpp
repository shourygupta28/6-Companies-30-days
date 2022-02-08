class Solution
{
public:
    bool isLeaf(int x, int y, int n, vector<vector<int>> &grid)
    {
        int val = grid[x][y];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[x + i][y + j] != val)
                    return false;
            }
        }

        return true;
    }

    Node *_constructQuadTree(int x, int y, int n, vector<vector<int>> &grid)
    {
        if (n == 1)
            return new Node(grid[x][y], true);

        if (isLeaf(x, y, n, grid) == true)
            return new Node(grid[x][y], true);

        int leafSize = n / 2;

        Node *topLeft = _constructQuadTree(x, y, leafSize, grid);
        Node *topRight = _constructQuadTree(x, y + leafSize, leafSize, grid);
        Node *bottomLeft = _constructQuadTree(x + leafSize, y, leafSize, grid);
        Node *bottomRight = _constructQuadTree(x + leafSize, y + leafSize, leafSize, grid);

        return new Node(grid[x][y], false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        return _constructQuadTree(0, 0, grid.size(), grid);
    }
};