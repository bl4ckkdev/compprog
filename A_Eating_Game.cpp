#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            mx = max(nums[i], mx);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) cnt++;
        }

        cout << cnt << endl;
    }
}