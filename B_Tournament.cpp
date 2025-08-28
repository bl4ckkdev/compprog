#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, j, k; cin >> n >> j >> k;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int peak = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > peak) peak = nums[i];
        }

        if (k > 1) {
            cout << "YES" << endl;
        } else {
            if (nums[j-1] == peak) cout << "YES" << endl;
            else cout << "NO\n";
        }
    }
}