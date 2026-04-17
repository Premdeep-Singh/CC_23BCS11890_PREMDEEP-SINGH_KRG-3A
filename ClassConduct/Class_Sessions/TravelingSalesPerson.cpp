#include<bits/stdc++.h>

using namespace std;

class solution {
public:
    int travelingSalesmanCost(int n, vector<vector<int>> &dist) {
        int N = (1 << n); // Total masks to represent subsets of cities
        vector<vector<int>> dp(N, vector<int>(n, INT_MAX));

        // Base case: start from city 0 (A)
        dp[1][0] = 0;

        // Iterate over all masks
        for (int mask = 1; mask < N; mask++) {
            for (int u = 0; u < n; u++) {

                // If u not in mask → skip
                if (!(mask & (1 << u))) continue;

                // Try coming to u from v
                for (int v = 0; v < n; v++) {

                    if (v == u) continue;

                    // v must be in mask
                    if (!(mask & (1 << v))) continue;

                    int prevMask = mask ^ (1 << u); // Remove u from mask

                    if (dp[prevMask][v] == INT_MAX) continue;

                    int cost = dp[prevMask][v] + dist[v][u]; // Take cost needed to reach v + cost from v to u

                    if (cost < dp[mask][u]) {
                        dp[mask][u] = cost;
                    }
                }
            }
        }

        // Final answer (return to start)
        int finalMask = N - 1;
        int ans = INT_MAX;

        for (int i = 1; i < n; i++) {
            int cost = dp[finalMask][i] + dist[i][0];
            if (cost < ans) {
                ans = cost;
            }
        }

        return ans;
    }
};

int main(){
    int cities = 4;

    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    solution sol;
    int result = sol.travelingSalesmanCost(cities, dist);

    cout << "Minimum Cost: " << result << endl;

    return 0;
}