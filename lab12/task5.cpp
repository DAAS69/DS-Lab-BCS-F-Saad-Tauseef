#include <iostream>
using namespace std;

const int NUM_VERTICES = 5;

void printAdjacencyList(int adjacencyList[NUM_VERTICES][NUM_VERTICES], int neighborsCount[NUM_VERTICES]) {
    cout << "Adjacency List:" << endl;
    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
        cout << vertex + 1 << ":";
        for (int neighborIndex = 0; neighborIndex < neighborsCount[vertex]; neighborIndex++) {
            cout << adjacencyList[vertex][neighborIndex];
            if (neighborIndex < neighborsCount[vertex] - 1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printAdjacencyMatrix(int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES]) {
    cout << "Adjacency Matrix:" << endl;
    for (int row = 0; row < NUM_VERTICES; row++) {
        for (int col = 0; col < NUM_VERTICES; col++) {
            cout << adjacencyMatrix[row][col];
            if (col < NUM_VERTICES - 1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int startVertex, int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES]) {
    cout << "BFS:" << endl;

    int visited[NUM_VERTICES] = {0};
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        cout << currentVertex + 1;

        if (front < rear) cout << " ";

        for (int neighbor = 0; neighbor < NUM_VERTICES; neighbor++) {
            if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                queue[rear++] = neighbor;
                visited[neighbor] = 1;
            }
        }
    }
    cout << endl << endl;
}

void DFSUtil(int currentVertex, int visited[NUM_VERTICES], int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES]) {
    visited[currentVertex] = 1;
    cout << currentVertex + 1;

    for (int neighbor = 0; neighbor < NUM_VERTICES; neighbor++) {
        if (adjacencyMatrix[currentVertex][neighbor] == 1 && !visited[neighbor]) {
            cout << " ";
            DFSUtil(neighbor, visited, adjacencyMatrix);
        }
    }
}

void DFS(int startVertex, int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES]) {
    cout << "DFS:" << endl;
    int visited[NUM_VERTICES] = {0};
    DFSUtil(startVertex, visited, adjacencyMatrix);
    cout << endl << endl;
}

int main() {
    int adjacencyMatrix[NUM_VERTICES][NUM_VERTICES] = {0};

    int edges[][2] = {
        {1, 4},
        {2, 4}, {2, 5},
        {3, 5},
        {4, 5}
    };

    int numEdges = 5;

    for (int i = 0; i < numEdges; i++) {
        int vertexU = edges[i][0] - 1;
        int vertexV = edges[i][1] - 1;
        adjacencyMatrix[vertexU][vertexV] = 1;
        adjacencyMatrix[vertexV][vertexU] = 1;
    }

    int adjacencyList[NUM_VERTICES][NUM_VERTICES];
    int neighborsCount[NUM_VERTICES] = {0};

    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
        neighborsCount[vertex] = 0;
        for (int neighbor = 0; neighbor < NUM_VERTICES; neighbor++) {
            if (adjacencyMatrix[vertex][neighbor] == 1) {
                adjacencyList[vertex][neighborsCount[vertex]++] = neighbor + 1;
            }
        }
    }

    printAdjacencyList(adjacencyList, neighborsCount);
    printAdjacencyMatrix(adjacencyMatrix);

    BFS(0, adjacencyMatrix);
    DFS(0, adjacencyMatrix);

    return 0;
}
