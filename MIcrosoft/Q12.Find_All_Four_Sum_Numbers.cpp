class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {

        set<vector<int>> ans;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int target = k - (arr[i] + arr[j]);
                int l = j + 1, r = n - 1;

                while (l < r)
                {
                    int x = (arr[l] + arr[r]);

                    if (target == x)
                    {
                        ans.insert({arr[i], arr[j], arr[l], arr[r]});

                        while (l < r && arr[l] == arr[l + 1])
                            l++;
                        while (l < r && arr[r] == arr[r - 1])
                            r--;
                        l++;
                        r--;
                    }
                    else if (x < target)
                        l++;
                    else
                        r--;
                }

                while (j < n - 2 && arr[j] == arr[j + 1])
                    j++;
            }
            while (i < n - 1 && arr[i] == arr[i + 1])
                i++;
        }

        vector<vector<int>> res(ans.begin(), ans.end());

        return res;
    }
};