class Solution
{
public:
    string largest_no = "";
    void findMax(int indx, string str, int k)
    {
        if (k == 0)
            return;

        int n = str.length();
        char max_d = str[indx];

        for (int i = indx + 1; i < n; i++)
        {
            if (str[i] > max_d)
                max_d = str[i];
        }

        if (max_d != str[indx])
            k--;

        for (int i = n - 1; i >= indx; i--)
        {
            if (str[i] == max_d)
            {
                swap(str[i], str[indx]);

                if (str.compare(largest_no) > 0)
                    largest_no = str;

                findMax(indx + 1, str, k);
                swap(str[i], str[indx]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        findMax(0, str, k);
        return largest_no;
    }
};