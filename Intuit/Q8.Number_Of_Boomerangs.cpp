class Solution
{

public:
    int getDistance(vector<int> a, vector<int> b)
    {
        return ((a[0] - b[0]) * (a[0] - b[0])) + ((a[1] - b[1]) * (a[1] - b[1]));
    }

    int numberOfBoomerangs(vector<vector<int>> &points)
    {

        int n = points.size(), boomerangs = 0;
        for (int i = 0; i < n; i++)
        {

            unordered_map<int, int> dist;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int d = getDistance(points[i], points[j]);

                    if (dist.find(d) != dist.end())
                        boomerangs += dist[d];

                    dist[d]++;
                }
            }
        }
        return boomerangs * 2;
    }
};