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
void bfs(int s, int n, string arr[]) {
    queue<int> bfsq;
    if (!visited[s]) {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;
        while (!bfsq.empty()) {
            int v = bfsq.front();
            for (int i = 0; i < n; i++) {
                if (adj_mat[v][i] && !visited[i]) {
                    cout << arr[i] << " ";
                    visited[i] = true;
                    bfsq.push(i);
                }
            }
            bfsq.pop();
        }
    }
}

int main() {
    cout << "Enter no. of cities: ";
    int n;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";
    for (int i = 0; i < n; i++) {
        cout << "\n" << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
    cout << "Enter Starting Vertex: ";
    int start;
    cin >> start;
    cout << "DFS: ";
    dfs(start, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(start, n, cities);
    return 0;
}
