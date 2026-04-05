#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        // Build graph
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        // {stops, {node, cost}}
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, p] = q.front();
            q.pop();

            int node = p.first;
            int cost = p.second;

            if (stops > k) continue;

            for (auto &[adjNode, price] : adj[node]) {
                if (cost + price < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + price;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 1;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl; // Output: 200

    n = 3;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    src = 0; dst = 2; k = 0;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl; // Output: 500
    return 0;
}