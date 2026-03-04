#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        bool can = false;
        for (int i = 1; i < n; i++) {
            if (nums[i]-nums[i-1]<0) {
                can = true;
                break;
            }
        }

        cout << (can ? 1 : n) << endl;
    }
}