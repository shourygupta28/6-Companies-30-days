
class Triplet
{
public:
    int row, col, val;
    Triplet(int _row, int _col, int _val)
    {
        row = _row;
        col = _col;
        val = _val;
    }
};

class comp
{
public:
    bool operator()(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {

        priority_queue<Triplet, vector<Triplet>, comp> pq;

        int mini = 0, maxi = INT_MIN, row, col, val, next_val;

        for (int i = 0; i < k; i++)
        {

            if (KSortedArray[i][0] > maxi)
                maxi = KSortedArray[i][0];
            pq.push(Triplet(i, 0, KSortedArray[i][0]));
        }

        mini = pq.top().val;

        int l = mini;
        int r = maxi;
        int diff = r - l;

        while (true)
        {
            auto u = pq.top();
            pq.pop();

            row = u.row;
            col = u.col;
            val = u.val;

            if (col + 1 >= n)
                break;

            next_val = KSortedArray[row][col + 1];

            pq.push(Triplet(row, col + 1, next_val));

            mini = pq.top().val;

            if (next_val > maxi)
                maxi = next_val;

            if (maxi - mini < diff)
            {
                l = mini;
                r = maxi;
                diff = r - l;
            }
        }

        return {l, r};
    }
};