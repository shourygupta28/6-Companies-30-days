class Solution
{
public:
    bool dfs(vector<int> &ans, int target, int i)
    {
        if (i == ans.size())
            return target == 0;

        int n = ans[i];

        if (dfs(ans, target, i + 1))
            return true;

        ans[i] = -n;

        if (dfs(ans, target - n, i + 1))
            return true;

        ans[i] = n;
        return false;
    }

    vector<int> recoverArray(int n, vector<int> &A)
    {
        int mn = *min_element(begin(A), end(A));

        for (int &n : A)
            n += -mn;

        multiset<int> s(begin(A), end(A)), tmp;
        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            tmp.clear();
            int num = *next(s.begin());
            ans.push_back(num);

            while (s.size())
            {
                int first = *s.begin();
                tmp.insert(first);
                s.erase(s.begin());
                s.erase(s.find(first + num));
            }
            swap(s, tmp);
        }

        dfs(ans, -mn, 0);
        return ans;
    }
};