#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int result = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int duplicates = 0;
            int maxPointsOnLine = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                string slope = to_string(dx) + "/" + to_string(dy);
                mp[slope]++;
                maxPointsOnLine = max(maxPointsOnLine, mp[slope]);
            }

            result = max(result, maxPointsOnLine + duplicates + 1);
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
};


int main() {
    Solution sol;
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    cout << sol.maxPoints(points) << endl; // Output: 3

    points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << sol.maxPoints(points) << endl; // Output: 4
    return 0;
}