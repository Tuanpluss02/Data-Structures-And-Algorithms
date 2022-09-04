#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 15;
int vertices, edges, start, finish;

vector<int> Graph[MAX];
bool visited[MAX];

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
void BFS(int s, bool print)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        if (print)
            cout << tmp << " ";
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
void connectedComponent(string option = "DFS")
{
    int count = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            count++;
            cout << "Connected components " << count << ": ";
            if (option == "DFS")
                DFS(i, true);
            else
                BFS(i, true);
            cout << endl;
        }
    }
    cout << "Total number of connected components are: " << count << endl;
}
void isConnected(string option = "DFS")
{
    int count = 0;
    memset(visited, false, sizeof(visited));
    if (option == "DFS")
        DFS(1, false);
    else
        BFS(1, false);
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        {
            count++;
        }
    }
    if (count != vertices)
    {
        cout << "The given graph is connected" << endl;
        connectedComponent(option);
    }
    else
    {
        cout << "The given graph is not connected" << endl;
    }
}

int main()
{
    cin >> vertices >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    // check connected components
    cout << "Using BFS: " << endl;
    isConnected("BFS");
    cout << "--------------------------" << endl;
    cout << "Using DFS: " << endl;
    isConnected("DFS");
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

ouput:

Using BFS:
The given graph is connected
Connected components 1: 1 2 4 7 3 6 8 9 10 5 11 12 13
Total number of connected components are: 1
--------------------------
Using DFS:
The given graph is connected
Connected components 1: 1 2 3 5 4 6 7 8 11 12 9 13 10
Total number of connected components are: 1

*/