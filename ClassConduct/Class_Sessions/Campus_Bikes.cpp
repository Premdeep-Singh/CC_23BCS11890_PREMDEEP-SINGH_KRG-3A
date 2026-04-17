// Write your solution here

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<vector<int>> workers, vector<vector<int>> bikes) {
        vector<tuple<int, int, int>> pairs;

        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                pairs.push_back({dist, i, j});
            }
        }

        sort(pairs.begin(), pairs.end());
        vector<int> output(workers.size(), -1);
        unordered_set<int> bikesTaken;
        
        for (auto &[dist, w, b] : pairs) {
            if (!bikesTaken.count(b) && output[w] == -1) {
                output[w] = b;
                bikesTaken.insert(b);
            }
        }

        return output;
    }
};
