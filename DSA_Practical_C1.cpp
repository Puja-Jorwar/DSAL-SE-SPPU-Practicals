#include <iostream>
#include <queue>
using namespace std;

// Global variables to store adjacency matrix and visited status
int adj_mat[50][50] = {0};
int visited[50] = {0};

// Depth-First Search (DFS) traversal function
void dfs(int s, int n, string arr[]) {
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++) {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);
    }
}

// Breadth-First Search (BFS) traversal function
void bfs(int s, in#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0, 0};
int visited[50] = {0};

void dfs(int s, int n, string arr[])
{
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);
    }
}

void bfs(int s, int n, string arr[])
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int v;
    queue<int> bfsq;
    if (!visited[s])
    {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;
        while (!bfsq.empty())
        {
            v = bfsq.front();
            for (int i = 0; i < n; i++)
            {
                if (adj_mat[v][i] && !visited[i])
                {
                    cout << arr[i] << " ";
                    visited[i] = true;
                    bfsq.push(i);
                }
            }
            bfsq.pop();
        }
    }
}

int main()
{
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
    cout << "Enter Starting Vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(u, n, cities);
    return 0;
}


/* OUTPUT:

Enter no. of cities: 4
Enter city #0 (Airport Code): 1
Enter city #1 (Airport Code): 2
Enter city #2 (Airport Code): 3
Enter city #3 (Airport Code): 4

Your cities are:
city #0: 1
city #1: 2
city #2: 3
city #3: 4
Enter distance between 1 and 2 : 12
Enter distance between 1 and 3 : 24
Enter distance between 1 and 4 : 36
Enter distance between 2 and 3 : 48
Enter distance between 2 and 4 : 60
Enter distance between 3 and 4 : 72

        1               2               3               4
1       0               12              24              36

2       12              0               48              60

3       24              48              0               72

4       36              60              72              0
Enter Starting Vertex: 12
DFS:
--------------------------------
*/

