#include <bits/stdc++.h>

using namespace std;

vector<int> topologicalSort(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> inDegree(V, 0);
    for (const auto& neighbors : graph) {
        for (int neighbor : neighbors) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int neighbor : graph[u]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topoOrder.size() != V) {
        cerr << "Graph has a cycle, topological sort not possible" << endl;
        return {};
    }

    return topoOrder;
}


int main() {
    int V = 6;
    vector<vector<int>> graph(V);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);


    vector<int> topoOrder = topologicalSort(graph);
    cout << "Topological Sort: ";
    for (int vertex : topoOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}