#include<bits/stdc++.h>

using namespace std;

class solution {
    public:
    int minMatrixChain(vector<int> &arr, int n){
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 1; i < n; i++){
            dp[i][i] = 0;
        }

        for(int len = 2; len < n; len++){
            for(int i = 1; i <= n - len + 1; i++){
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for(int k = i; k < j; k++){
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n - 1];
    }
};


int main(){
    solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    cout << sol.minMatrixChain(arr, n) << endl; // Output: 26000
    return 0;
}