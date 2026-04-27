#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primsMST(int V, int E, vector<vector<int>> &edges) {
        
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Prim's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, false);
        int totalWeight = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [weight, vertex] = pq.top();
            pq.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                totalWeight += weight;

                for (auto &[adjVertex, adjWeight] : adj[vertex]) {
                    if (!visited[adjVertex]) {
                        pq.push({adjWeight, adjVertex});
                    }
                }
            }
        }

        return totalWeight;
    }
};

int main() {
    int V, E;
    // cin >> V >> E;
    V = 3, E = 3;
    vector<vector<int>> edges(E, vector<int>(3));
    // for (int i = 0; i < E; i++) {
    //     cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    // }

    edges = {{0,1,5},
             {1,2,3},
             {0,2,1}
            };
            
    Solution solution;
    cout << "Total Weight of MST: " << solution.primsMST(V, E, edges) << endl; // Output: 4

    return 0;
}


