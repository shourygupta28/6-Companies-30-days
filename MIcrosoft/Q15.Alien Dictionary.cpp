class Solution
{
public:
    string topologicalSort(int N, vector<int> adj[])
    {
        vector<int> indegree(N, 0);
        queue<int> q;
        string str = "";

        for (int i = 0; i < N; i++)
            for (auto it : adj[i])
                indegree[it]++;

        for (int i = 0; i < N; i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            str += char(node + 97);
            count++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return (count == N) ? str : "";
    }

    string findOrder(string dict[], int N, int K)
    {

        vector<int> adj[K];

        for (int p = 1; p < N; p++)
        {
            string word1 = dict[p - 1];
            string word2 = dict[p];

            int len1 = word1.length(), len2 = word2.length(), i = 0, j = 0;

            while (i < len1 && j < len2)
            {
                if (word1[i] != word2[j])
                {
                    adj[word1[i] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
                else
                {
                    i++;
                    j++;
                }
            }
        }

        string str = topologicalSort(K, adj);

        return str;
    }
};