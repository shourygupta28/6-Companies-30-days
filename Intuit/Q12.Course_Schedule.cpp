class Solution
{
public:
    vector<int> topologicalSort(int N, vector<int> adj[])
    {

        vector<int> toposort;
        vector<int> indegree(N, 0);
        queue<int> q;

        for (int i = 0; i < N; i++)
            for (auto it : adj[i])
                indegree[it]++;

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();
            toposort.push_back(u);

            for (auto it : adj[u])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (toposort.size() == N)
            return toposort;
        else
            return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> adj[numCourses];

        for (auto x : prerequisites)
            adj[x[1]].push_back(x[0]);

        return topologicalSort(numCourses, adj);
    }
};