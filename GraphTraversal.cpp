#include <iostream>
#include <queue>
using namespace std;
#define MAX_VERTICES 8

void addEdge(int** adj, int u, int v) {
    adj[u][v] = 1;
}

void BFS(int** adj, int startVertex) {
    bool* visited = new bool[MAX_VERTICES];
    for (int i = 0; i <= MAX_VERTICES; ++i)
        visited[i] = false;
    queue<int> q;

    // push the starting vertex into the queue
    q.push(startVertex);

    // a while loop that runs until the queue is empty
    while (!q.empty()) {
        // the vertex that is being visited in the current iteration
        int visitedVertex = q.front();
        // remove the visited vertex from the queue
        q.pop();
        // print the vertex that has been visited
        cout << visitedVertex << " ";
        // mark the vertex as 'visited' to avoid cycles
        visited[visitedVertex] = true;

        // loop through all the vertices and if a vertex is adjacent to the visited vertex and has not been visited, add it to the queue, and mark it as visited
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (adj[visitedVertex][i] == 1 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }


    

//write your code here


    delete[] visited;
}

int main() {
    int** adj = new int*[MAX_VERTICES];
    for (int i = 0; i <= MAX_VERTICES; ++i)
        adj[i] = new int[MAX_VERTICES];
    // Initialize adjacency matrix with zeros
    for (int i = 0; i <= MAX_VERTICES; ++i)
        for (int j = 0; j <= MAX_VERTICES; ++j)
            adj[i][j] = 0;
    // Adding edges based on the given connections
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 6);
    addEdge(adj, 1, 5);
    addEdge(adj, 6, 3);
    addEdge(adj, 6, 7);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 7, 4);
    addEdge(adj, 7, 8);
    addEdge(adj, 4, 8);
    int startVertex = 2;  // Starting vertex

    BFS(adj, startVertex);
    // Deallocate memory
    for (int i = 0; i <= MAX_VERTICES; ++i)
        delete[] adj[i];
    delete[] adj;
    return 0;}
