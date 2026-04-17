#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findParent(vector<int> &parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    pair<int, vector<vector<int>>> solve(vector<vector<int>> &edges, int V) {
        vector<int> parent(V + 1);

        // 1-based initialization
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        // Union
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int pu = findParent(parent, u);
            int pv = findParent(parent, v);
            if (pu != pv) {
                parent[pu] = pv;
            }
        }

        // Find components
        unordered_set<int> st;
        for (int i = 1; i <= V; i++) {
            st.insert(findParent(parent, i));
        }

        vector<int> comps(st.begin(), st.end());
        vector<vector<int>> newRoads;

        // Connect components
        for (int i = 1; i < comps.size(); i++) {
            newRoads.push_back({comps[i - 1], comps[i]});
        }

        return {(int)newRoads.size(), newRoads};
    }
};

int main() {
    Solution sol;
    int c = 4;
    vector<vector<int>> edges = {{1, 2}, {3, 4}};

    auto result = sol.solve(edges, c);

    cout << result.first << endl;
    for (auto &road : result.second) {
        cout << road[0] << " " << road[1] << endl;
    }
}