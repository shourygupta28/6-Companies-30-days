class Solution
{
public:
    long long m = 1000000007;

    long long power(int N, int R)
    {
        long long res = 1;
        N = N % m;

        while (R > 0)
        {

            if (R & 1)
            {
                res = (res % m * N % m) % m;
                R--;
            }

            R = R >> 1;
            N = (N % m * N % m) % m;
        }

        return res % m;
    }
};