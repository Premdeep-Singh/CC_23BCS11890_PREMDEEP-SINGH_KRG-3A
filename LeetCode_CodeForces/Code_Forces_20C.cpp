#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;


vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int V = graph.size();
    vector<int> dist(V, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (const auto& [v, weight] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }


    int start = 1;
    vector<int> shortestPaths = dijkstra(graph, start);

    for (int i = 2; i <= n; i++) {
        if (shortestPaths[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << shortestPaths[i] << " ";
        }
    }
    cout << endl;

    return 0;
}