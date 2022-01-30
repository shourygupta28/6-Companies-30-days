public:
vector<int> calculateSpan(int price[], int n)
{

    stack<pair<int, int>> st;
    vector<int> ans;
    reverse(price, price + n);

    int pos = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int t = -1;
        while (!st.empty() && price[i] >= st.top().first)
        {
            t = st.top().second;
            st.pop();
        }

        if (!st.empty())
            ans.push_back(pos - st.top().second);
        else
            ans.push_back(pos - t);
        st.push({price[i], pos++});
    }
    return ans;
}
}
;