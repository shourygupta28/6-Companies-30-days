class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {

        int n = grid.size(), min_swaps = 0, i, j;
        int arr[n];

        for (i = 0; i < n; i++)
        {
            int trailing_zeroes = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] != 1; j--)
            {
                if (grid[i][j] == 0)
                    trailing_zeroes++;
            }
            arr[i] = trailing_zeroes;
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] < n - i - 1)
            {

                for (j = i + 1; j < n; j++)
                {
                    if (arr[j] >= n - i - 1)
                        break;
                }

                if (j == n)
                    return -1;

                while (j > i)
                {
                    swap(arr[j - 1], arr[j]);
                    j--;
                    min_swaps++;
                }
            }
        }

        return min_swaps;
    }
};