#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;


vector<vector<int>> floydWarshall(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    vector<vector<int>> shortestPaths = floydWarshall(graph);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (shortestPaths[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << shortestPaths[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}