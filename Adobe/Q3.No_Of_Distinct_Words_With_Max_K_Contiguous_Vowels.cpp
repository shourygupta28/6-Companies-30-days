typedef long long int ll;
class Solution
{
public:
    ll power(ll n, ll p, ll mod)
    {
        n = n % mod;

        if (p == 0)
            return 1;

        if (p % 2 == 0)
            return ((power(n, p / 2, mod) % mod) * (power(n, p / 2, mod) % mod)) % mod;
        else
            return (n * (power(n, p / 2, mod) % mod) * (power(n, p / 2, mod) % mod)) % mod;
    }

    ll kvowelwords(int N, int K)
    {

        ll dp[N + 1][K + 1];
        memset(dp, 0, sizeof(dp));
        ll mod = 1000000007, i, j, sum = 1;

        for (i = 1; i <= N; i++)
        {
            dp[i][0] = sum * 21;
            dp[i][0] = dp[i][0] % mod;
            sum = dp[i][0];

            for (j = 1; j <= K && j <= N; j++)
            {

                if (i == j)
                {
                    dp[i][j] = power(5, i, mod);
                }

                else
                {
                    dp[i][j] = dp[i - 1][j - 1] * 5;
                    dp[i][j] = dp[i][j] % mod;
                }

                sum += dp[i][j];
                sum = sum % mod;
            }
        }
        return sum;
    }
};