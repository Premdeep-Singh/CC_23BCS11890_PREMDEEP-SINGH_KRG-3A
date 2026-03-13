/*
Given an integer array nums where every element appears three times except for one, which appears 
exactly once. Find the single element and return it.
*/

#include <bits/stdc++.h>

using namespace std;

int SingleNumber(vector<int>& nums) {
    int one = 0, two = 0;

    for (auto num : nums) {
        one = (one ^ num) & ~two;
        two = (two ^ num) & ~one;
    }

    return one;
}

int main() {
    vector<int> nums = {2, 2, 3, 2};
    cout << SingleNumber(nums) << endl; // Output: 3

    nums = {0, 1, 0, 1, 0, 1, 99};
    cout << SingleNumber(nums) << endl; // Output: 99
    return 0;
}