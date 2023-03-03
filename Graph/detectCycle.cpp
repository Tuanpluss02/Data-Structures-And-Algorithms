#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 15;
int vertices, edges, start, finish;

vector<int> Graph[MAX];
bool visited[MAX];
int parent[MAX];
vector<int> trace;

bool DFS(int s, int par)
{
    visited[s] = true;
    for (int v : Graph[s])
    {
        if (!visited[v])
        {
            // parent[v] = s;
            return DFS(v, s);
        }
        else if (v != par)
        {
            // start = v;
            // finish = par;
            // while (start != finish)
            // {
            //     trace.push_back(finish);
            //     finish = parent[finish];
            // }
            // reverse(trace.begin(), trace.end());
            return true;
        }
    }
    return false;
}

bool BFS(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int v : Graph[tmp])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                parent[v] = tmp;
            }
            else if (v != parent[tmp])
            {
                // start = v;
                // finish = tmp;
                // trace.push_back(start);
                // while (finish != start)
                // {
                //     trace.push_back(finish);
                //     finish = parent[finish];
                //     cout << finish << " " << parent[finish] << endl;
                // }
                // trace.push_back(start);
                // reverse(trace.begin(), trace.end());
                return true;
            }
        }
    }
    return false;
}

void hasCycle(string option = "DFS")
{
    memset(visited, false, sizeof(visited));
    // fill(parent, parent + MAX, 0);
    bool Result = option == "DFS" ? DFS(1, 0) : BFS(1);
    if (Result)
    {
        cout << "The given graph has cycles: " << endl;
        // for (int i : trace)
        //     cout << i << " ";
    }
    else
        cout << "The given graph has no cycles" << endl;
}

int main()
{
    cin >> vertices >> edges;
    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    hasCycle("DFS");
    system("pause");
    return 0;
}