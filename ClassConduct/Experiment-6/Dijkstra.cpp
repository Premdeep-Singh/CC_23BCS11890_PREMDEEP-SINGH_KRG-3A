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
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);

    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({3, 6});

    int start = 0;
    vector<int> shortestPaths = dijkstra(graph, start);

    for (int i = 0; i < V; i++) {
        if (shortestPaths[i] == INF) {
            cout << "INF ";
        } else {
            cout << shortestPaths[i] << " ";
        }
    }
    cout << endl;

    return 0;
}