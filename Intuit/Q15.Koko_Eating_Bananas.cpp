class Solution
{
public:
    bool check(int k, vector<int> &piles, int h)
    {
        int n = piles.size(), hrs = 0;
        for (int i = 0; i < n; i++)
        {
            hrs += (piles[i] / k);

            if (piles[i] % k != 0)
                hrs++;

            if (hrs > h)
                return false;
        }

        if (hrs <= h)
            return true;
        return false;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size(), low = 1, high = INT_MIN;

        for (int i = 0; i < n; i++)
            high = max(high, piles[i]);

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            bool workable = check(mid, piles, h);

            if (workable)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};