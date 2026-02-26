#include<bits/stdc++.h>
using namespace std;


class solution {
public:
    const int p = 31;
    const int mod = 1e9 + 7;

    vector<int> kmp(string str, string pattern) {
        vector<int> result;
        int n = str.size();
        int m = pattern.size();

        if (m > n) return {-1};
        vector<int> lps(m, 0);
        // Preprocess the pattern to create the longest prefix-suffix (LPS) array
        for (int i = 1; i < m; ) {
            if (pattern[i] == pattern[lps[i - 1]]) {
                lps[i] = lps[i - 1] + 1;
                i++;
            } else {
                if (lps[i - 1] != 0) {
                    lps[i] = lps[lps[i - 1] - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Search for the pattern in the string using the LPS array
        for (int i = 0, j = 0; i < n; ) {
            if (str[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && str[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        if (result.empty())
            result.push_back(-1);

        return result;
    }
};

int main() {
    string str = "abcde";
    string pattern = "cde";

    vector<int> result = solution().kmp(str, pattern);
    for(int index : result) {
        cout << index << endl;
    }
}