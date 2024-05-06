#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> visited;

public:
    Graph() {
        adjList.resize(MAX);
        visited.resize(MAX, false);
    }

    void createAdjacencyList() {
        int n, m, v1, v2;
        char ans;
        cout << "Enter the number of vertices: ";
        cin >> n;
        cout << "Enter the number of edges: ";
        cin >> m;
        cout << "\nEnter edges (vertices should start from 0):\n";
        for (int k = 0; k < m; k++) {
            cin >> v1 >> v2;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1); // Assuming undirected graph
        }
        displayAdjacencyList(n);
    }

    void displayAdjacencyList(int n) {
        cout << "\nThe adjacency list of the graph is:\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " : ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfs(int v) {
        cout << "The BFS of the Graph is\n";
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty()) {
            v = q.front();
            q.pop();
            cout << v << " ";
            for (int u : adjList[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }

    void dfsUtil(int v) {
        cout << v << " ";
        visited[v] = true;
        for (int u : adjList[v]) {
            if (!visited[u]) {
                dfsUtil(u);
            }
        }
    }

    void dfs(int v) {
        cout << "The DFS of the Graph is\n";
        dfsUtil(v);
    }

    void menu() {
        int choice, v1;
        cout << "\n\nMENU:\n";
        cout << "1. Create Adjacency List\n";
        cout << "2. Breadth First Search (BFS)\n";
        cout << "3. Depth First Search (DFS)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createAdjacencyList();
                break;
            case 2:
                cout << "\nEnter the initial vertex for BFS: ";
                cin >> v1;
                if (v1 >= MAX)
                    cout << "Invalid Vertex\n";
                else {
                    visited.assign(MAX, false);
                    bfs(v1);
                }
                break;
            case 3:
                cout << "\nEnter the initial vertex for DFS: ";
                cin >> v1;
                if (v1 >= MAX)
                    cout << "Invalid Vertex\n";
                else {
                    visited.assign(MAX, false);
                    dfs(v1);
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid Choice\n";
        }
    }
};

int main() {
    Graph g;
    while (true) {
        g.menu();
    }
    return 0;
}
