class Solution
{
public:
    string nextPermutation(string a, int n)
    {

        int i, j;
        for (i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
                break;
        }

        if (i < 0)
            return "-1";

        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] > a[i])
            {
                swap(a[i], a[j]);
                break;
            }
        }

        string a1 = a.substr(0, i + 1);
        string a2 = a.substr(i + 1);
        reverse(a2.begin(), a2.end());
        return a1 + a2;
    }

    string nextPalin(string N)
    {

        int n = N.length();

        string half = N.substr(0, n / 2);

        string str = nextPermutation(half, n);

        if (str == "-1")
            return "-1";

        string rev = str;
        reverse(rev.begin(), rev.end());

        if (n % 2 == 0)
        {
            str = str + rev;
        }
        else
        {
            char ch = N[n / 2];
            str = str + ch;
            str += rev;
        }

        return str;
    }
};