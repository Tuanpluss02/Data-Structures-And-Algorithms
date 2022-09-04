#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 15;
int vertices, edges, start, finish;

vector<int> Graph[MAX];
bool visited[MAX];

bool DFS(int s, int parent)
{
    visited[s] = true;
    for (int v : Graph[s])
    {
        if (s == parent)
            continue;
        if (visited[v])
            return true;
        if (DFS(v, s))
            return true;
    }
    return false;
}

bool hasCycle()
{
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= vertices; i++)
    {
        if (visited[i])
            continue;
        if (DFS(i, -1))
            return true;
    }
    return false;
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
    if (hasCycle())
        cout << "The given graph has cycles." << endl;
    else
        cout << "The given graph has no cycles." << endl;
}