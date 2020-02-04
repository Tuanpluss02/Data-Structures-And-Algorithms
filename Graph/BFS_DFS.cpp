#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 15;
int vertices, edges, start, finish;

vector<int> Graph[MAX], path;
bool visited[MAX];

void DFS(int s, int d)
{
    visited[s] = true;
    path.push_back(s);
    if (s == d)
    {
        return;
    }
    for (int v : Graph[s])
    {
        if (!visited[v])
        {
            if (path.back() == d)
                return;
            DFS(v, d);
        }
    }
}

void DFS(int s)
{
    visited[s] = true;
    for (int v : Graph[s])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

void BFS(int s, int d)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        path.push_back(u);
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

void BFS(int s)
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
            }
        }
    }
}
