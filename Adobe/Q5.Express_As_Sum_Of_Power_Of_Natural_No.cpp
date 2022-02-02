typedef long long int ll;
class Solution
{
public:
    ll numOfWays(int n, int x)
    {
        ll dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        dp[1] = 1;
        ll maxi = pow(n, 1.0 / x);
        for (ll i = 2; i <= maxi; i++)
        {
            ll p = pow(i, x);
            for (ll j = n; j >= p; j--)
                dp[j] = dp[j] + dp[j - p];
        }

        return dp[n];
    }
};
