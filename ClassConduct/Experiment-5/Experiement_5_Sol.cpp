#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll P = 31;          
const int MAXL = 600005; 

ll power[MAXL];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute powers of P
    power[0] = 1;
    for (int i = 1; i < MAXL; i++)
        power[i] = (power[i - 1] * P) % MOD;

    int n, m;
    cin >> n >> m;

    unordered_set<ll> hashes;

    // Read dictionary strings
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        ll hashVal = 0;
        for (int j = 0; j < s.size(); j++) {
            ll val = (s[j] - 'a' + 1);
            hashVal = (hashVal + val * power[j]) % MOD;
        }

        hashes.insert(hashVal);
    }

    // Process queries
    while (m--) {
        string s;
        cin >> s;

        ll originalHash = 0;
        for (int j = 0; j < s.size(); j++) {
            ll val = (s[j] - 'a' + 1);
            originalHash = (originalHash + val * power[j]) % MOD;
        }

        bool found = false;

        for (int j = 0; j < s.size() && !found; j++) {
            ll oldVal = (s[j] - 'a' + 1);

            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[j]) continue;

                ll newVal = (c - 'a' + 1);

                ll newHash = originalHash;
                newHash = (newHash - oldVal * power[j] % MOD + MOD) % MOD;
                newHash = (newHash + newVal * power[j] % MOD) % MOD;

                if (hashes.count(newHash)) {
                    found = true;
                    break;
                }
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}