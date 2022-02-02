class Solution
{
public:
    int lengthOfLongestAP(int A[], int n)
    {

        int maxi = 2;
        vector<unordered_map<int, int>> dp(n);

        if (n <= 2)
            return n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = A[j] - A[i];
                if (dp[i].find(diff) != dp[i].end())
                    dp[j][diff] = dp[i][diff] + 1;
                else
                    dp[j][diff] = 2;
                maxi = max(maxi, dp[j][diff]);
            }
        }

        return maxi;
    }
};
