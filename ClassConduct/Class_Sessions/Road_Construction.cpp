#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findParent(unordered_map<int,int> &parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    vector<pair<int,int>> solve(vector<vector<int>> &edges) {
        unordered_map<int,int> parent, size;

        int components = 0;
        int maxSize = 0;

        vector<pair<int,int>> ans;

        for (auto &e : edges) {
            int u = e[0], v = e[1];

            // Initialize if not present
            if (!parent.count(u)) {
                parent[u] = u;
                size[u] = 1;
                components++;
            }
            if (!parent.count(v)) {
                parent[v] = v;
                size[v] = 1;
                components++;
            }

            int pu = findParent(parent, u);
            int pv = findParent(parent, v);

            if (pu != pv) {
                // Union by size
                if (size[pu] < size[pv]) swap(pu, pv);

                parent[pv] = pu;
                size[pu] += size[pv];
                components--;

                maxSize = max(maxSize, size[pu]);
            }

            // Handle isolated case
            maxSize = max({maxSize, size[findParent(parent, u)], size[findParent(parent, v)]});

            ans.push_back({maxSize, components});
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> newConstructions = {{1, 2}, {3, 4}};
    auto result = sol.solve(newConstructions);

    for (auto &p : result) {
        cout << p.first << " " << p.second << endl;
    }
}