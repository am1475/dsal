#include<iostream>
#include<queue>
#include<vector>
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

    void createAdjList() {
        int numEdges, numVertices, v1, v2;
        cout << "Enter the number of vertices:" << endl;
        cin >> numVertices;
        cout << "Enter the number of edges:" << endl;
        cin >> numEdges;
        cout << "Enter the edges (starting from 0)" << endl;
        for (int i = 0; i < numEdges; i++) {
            cin >> v1 >> v2;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        displayAdjList(numVertices);
    }

    void displayAdjList(int numVertices) {
        cout << "The adjacency list of the graph is:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

  void bfsUtil(queue<int>& q) {
    if (q.empty())
        return;

    int currentVertex = q.front();
    q.pop();
    cout << currentVertex << " ";

    // Process adjacent vertices of the current vertex
    for (int adjacentVertex : adjList[currentVertex]) {
        if (!visited[adjacentVertex]) {
            visited[adjacentVertex] = true;
            q.push(adjacentVertex);
        }
    }

    // Recursively call bfsUtil with the updated queue
    bfsUtil(q);
}

void bfs(int startVertex) {
    cout << "BFS of the graph starting from vertex " << startVertex << ":" << endl;
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    bfsUtil(q);
    cout << endl;
}


    void dfsUtil(int vertex) {
        cout << vertex << " ";
        visited[vertex] = true;
        for (int adjacentVertex : adjList[vertex]) {
            if (!visited[adjacentVertex]) {
                dfsUtil(adjacentVertex);
            }
        }
    }

    void dfs(int startVertex) {
        cout << "DFS of the graph starting from vertex " << startVertex << ":" << endl;
        dfsUtil(startVertex);
        cout << endl;
    }
};

int main() {
    Graph g;
    int initialVertex, bfsStartVertex;
    g.createAdjList();
    cout << "Enter the initial vertex for DFS:" << endl;
    cin >> initialVertex;
    g.dfs(initialVertex);
    cout << "Enter the initial vertex for BFS:" << endl;
    cin >> bfsStartVertex;
    g.bfs(bfsStartVertex);
    return 0;
}
