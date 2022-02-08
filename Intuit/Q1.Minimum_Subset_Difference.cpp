class Solution
{

public:
    vector<int> subsetSum(int n, int arr[], int sum)
    {
        bool dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        vector<int> v;
        for (int i = 0; i <= sum / 2; i++)
            if (dp[n][i])
                v.push_back(i);

        return v;
    }

    int minDifference(int arr[], int n)
    {

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        vector<int> S1 = subsetSum(n, arr, sum);

        int minDiff = INT_MAX;
        for (auto x : S1)
            minDiff = min(minDiff, sum - (2 * x));

        return minDiff;
    }
};
