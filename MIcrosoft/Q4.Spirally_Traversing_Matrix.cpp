class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {

        vector<int> ans;

        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, down = m - 1;

        while (left <= right && top <= down)
        {
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);

            for (int i = top + 1; i <= down - 1; i++)
                ans.push_back(matrix[i][right]);

            if (top != down)
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[down][j]);

            if (left != right)
                for (int i = down - 1; i >= top + 1; i--)
                    ans.push_back(matrix[i][left]);

            top++;
            left++;
            down--;
            right--;
        }

        return ans;
    }
};