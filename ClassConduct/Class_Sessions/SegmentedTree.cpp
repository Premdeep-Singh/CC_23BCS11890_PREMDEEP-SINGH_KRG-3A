#include<bits/stdc++.h>
using namespace std;


class segTree{
    vector<int> seg;
    vector<int> lazy;
public:
    void build(vector<int>& arr, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(arr, 2 * idx + 1, low, mid);
        build(arr, 2 * idx + 2, mid + 1, high);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        push(idx, low, high);
        if (r < low || high < l) return INT_MIN; // No overlap
        if (l <= low && high <= r) return seg[idx]; // Total overlap
        int mid = (low + high) / 2;
        int leftQuery = query(2 * idx + 1, low, mid, l, r);
        int rightQuery = query(2 * idx + 2, mid + 1, high, l, r);
        return max(leftQuery, rightQuery);
    }

    void push(int idx, int low, int high) {
        if (lazy[idx] != 0) {
            seg[idx] += lazy[idx];
            if (low != high) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    void updateRange(int idx, int low, int high, int l, int r, int val) {
        push(idx, low, high);
        if (r < low || high < l) return; // No overlap
        if (l <= low && high <= r) { // Total overlap
            lazy[idx] += val;
            push(idx, low, high);
            return;
        }
        int mid = (low + high) / 2;
        updateRange(2 * idx + 1, low, mid, l, r, val);
        updateRange(2 * idx + 2, mid + 1, high, l, r, val);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int solution(vector<int>& arr) {
        int n = arr.size();
        seg.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
        return 0;
    }
};


int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    segTree st;
    st.solution(arr);
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(0, 0, arr.size() - 1, l, r) << endl;
    }
    return 0;
}