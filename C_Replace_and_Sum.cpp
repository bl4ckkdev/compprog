#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, q; cin >> n >> q;

        vector<long long> nums(n), b(n);

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];
        }

        for (long long i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<long long, long long>> queries(q);
        for (long long i = 0; i < q; i++) cin >> queries[i].first >> queries[i].second;

        for (long long i = n-1; i >= 0; i--) {
            if (i == n-1) nums[i] = max(nums[i], b[i]);
            else {
                nums[i] = max(nums[i], max(b[i], nums[i+1]));
            }
        }

        vector<long long> prefix(n+1);

        for (long long i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        for (long long i = 0; i < q; i++) {
            cout << prefix[queries[i].second] - prefix[queries[i].first-1] << " ";
        }
        cout << endl;
    }
}