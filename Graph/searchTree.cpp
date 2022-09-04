#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 15;
int n, m, start, finish;

vector<int> Graph[MAX], path;
bool visited[MAX];

void DFS(int s = 1, int d = n)
{
    visited[s] = true;
    path.push_back(s);
    // cout << s << " ";
    if (s == d)
    {
        return;
    }
    for (int v : Graph[s])
    {
        if (!visited[v])
        {
            DFS(v, d);
            if (path.back() == d)
            {
                return;
            }
        }
    }
}

void BFS(int s = 1, int d = n)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        path.push_back(u);
        // cout << u << " ";
        if (u == d)
        {
            return;
        }
        for (int v : Graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        // Graph[v].push_back(u);
    }
    finish = n;
    cin >> start;
    cin >> finish;
    DFS(start, finish);
    if (path.back() == finish)
    {
        cout << "DFS path " << start << "->" << finish << " : ";
        for (auto i : path)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Not Found";
    }
    cout << endl;
    path.clear();
    memset(visited, false, sizeof(visited));
    BFS(start, finish);
    if (path.back() == finish)
    {
        cout << "BFS path " << start << "->" << finish << " : ";
        for (auto i : path)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Not Found";
    }
    return 0;
}