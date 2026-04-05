#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        for (int i = nums.size()-1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                nums[j] =  (nums[j] + nums[j+1]) % 10;
            }
        }

        return nums[0];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.triangularSum(nums) << endl; // Output: 8

    nums = {5};
    cout << sol.triangularSum(nums) << endl; // Output: 5
    return 0;
}