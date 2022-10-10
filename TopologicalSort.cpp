#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    // Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util(vector<vector<int>> &adj, vector<int> &visited, int v)
    {
        if (visited[v] == 1)
        {
            return true;
        }
        if (visited[v] == 2)
        {
            return false;
        }

        visited[v] = 1; // Mark current as visited
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (detectCycle_util(adj, visited, adj[v][i]))
            {
                return true;
            }
        }

        visited[v] = 2;
        return false;
    }

    // Cycle detection
    bool detectCycle(vector<vector<int>> &adj, int n)
    {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                if (detectCycle_util(adj, visited, i))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Topological sort
    void dfs(vector<vector<int>> &adj, int v, vector<bool> &visited, stack<int> &mystack)
    {
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); ++i)
        {
            if (!visited[adj[v][i]])
            {
                dfs(adj, adj[v][i], visited, mystack);
            }
        }

        mystack.push(v);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisties)
    {
        int n = prerequisties.size();
        vector<vector<int>> adj(numCourses);

        // Make adjancency list
        for (int i = 0; i < n; i++)
        {
            adj[prerequisties[i][1]].push_back(prerequisties[i][0]);
        }

        // Detect cycle... If present then return empty array
        vector<int> ans;
        if (detectCycle(adj, numCourses))
            return ans;

        // Find toposort and store it in stack
        stack<int> mystack;
        vector<bool> visited(numCourses, false);

        // Apply DFS and find topological sort
        for (int i = 0; i < numCourses; ++i)
        {
            if (!visited[i])
            {
                dfs(adj, i, visited, mystack);
            }
        }

        while (!mystack.empty())
        {
            ans.push_back(mystack.top());
            cout << mystack.top() << " ";
            mystack.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> edges =
        {
            {5, 2}, {4, 2}, {5, 0}, {0, 2}, {0, 3}, {3, 1}, {4, 1}

        };

    s.findOrder(6, edges);

    return 0;
}