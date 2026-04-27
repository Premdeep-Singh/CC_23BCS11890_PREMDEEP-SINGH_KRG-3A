#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceCows(vector<int> &stalls, int k, int distance) {
        int count = 1;
        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= distance) {
                count++;
                lastPosition = stalls[i];
                if (count == k) {
                    return true;
                }
            }
        }

        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1, high = stalls[n - 1] - stalls[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceCows(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};


int main() {
    int n, k;
    // cin >> n >> k;
    n = 5, k = 3;
    vector<int> stalls(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> stalls[i];
    // }
    stalls = {1, 2, 4, 8, 9};

    Solution solution;
    cout << "Maximum minimum distance: " << solution.aggressiveCows(stalls, k) << endl; // Output: 3 

    return 0;
}   