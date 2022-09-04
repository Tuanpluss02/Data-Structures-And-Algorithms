#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 15;
int n, m, start, finish;

vector<int> Graph[MAX];
bool visited[MAX];

void DFS(int s = 1, int d = n)
{
    visited[s] = true;
    if (s == d && d != n)
    {
        cout << "found" << endl;
        return;
    }
    cout << s << " ";
    for (int i = 0; i < Graph[s].size(); i++)
    {
        if (!visited[Graph[s][i]])
        {
            DFS(Graph[s][i], d);
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
        if (u == d && d != n)
        {
            cout << "Found" << endl;
            return;
        }
        cout << u << " ";
        for (int i = 0; i < Graph[u].size(); i++)
        {
            if (!visited[Graph[u][i]])
            {
                visited[Graph[u][i]] = true;
                q.push(Graph[u][i]);
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
        Graph[v].push_back(u);
    }
    finish = n;
    cin >> start;
    cin >> finish;
    cout << "DFS path " << start << "->" << finish << " : ";
    DFS(start, finish);
    cout << endl;
    memset(visited, false, sizeof(visited));
    cout << "BFS path " << start << "->" << finish << " : ";
    BFS(start, finish);
    return 0;
}