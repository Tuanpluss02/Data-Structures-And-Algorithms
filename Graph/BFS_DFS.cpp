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
    // cout << s << " ";
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

void DFS(int s, bool print)
{
    visited[s] = true;
    if (print)
        cout << s << " ";
    for (int v : Graph[s])
    {
        if (!visited[v])
        {
            DFS(v, print);
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

void testDFS()
{
    DFS(start, finish);
    if (path.back() == finish)
    {
        cout << "path " << start << "->" << finish << "using DFS: ";
        for (auto i : path)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
void testBFS()
{
    BFS(start, finish);
    if (path.back() == finish)
    {
        cout << "BFS path " << start << "->" << finish << " : ";
        for (auto i : path)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
void reset()
{
    path.clear();
    memset(visited, false, sizeof(visited));
}

int main()
{
    int u, v;
    cin >> u >> v;
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++)
    {
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        finish = vertices;
    }
    cin >> start;
    cin >> finish;
    // test BFS and DFS
    testDFS();
    reset();
    testBFS();
    return 0;
}
/* input:
13 15
1 2
2 3
3 5
2 4
4 6
2 6
1 4
1 7
7 8
7 9
7 10
8 11
8 12
9 12
12 13
2 6

output:
  DFS path 2->6 : 2 1 4 6
  BFS path 2->6 : 2 1 3 4 6
*/