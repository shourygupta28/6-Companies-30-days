//Function to return the name of candidate that received maximum votes.
vector<string> winner(string arr[], int n)
{

    map<string, int> mp;
    int maxvotes = 0;
    string winner = "";
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;

        if (mp[arr[i]] > maxvotes)
        {
            maxvotes = mp[arr[i]];
            winner = arr[i];
        }
        else if (mp[arr[i]] == maxvotes)
        {
            if (arr[i] < winner)
                winner = arr[i];
        }
    }

    vector<string> ans = {winner, to_string(maxvotes)};
    return ans;
}
}
;