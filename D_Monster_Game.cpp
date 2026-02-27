#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n; cin >> n;

        vector<long long> st(n), levels(n);

        for (long long i = 0; i < n; i++) {
            cin >> st[i];
        }

        for (long long i = 0; i < n; i++) {
            cin >> levels[i];
        }

        vector<long long> prefixlevels(n+1);

        sort(begin(st), end(st));

        for (long long i = 0; i < n; i++) {
            prefixlevels[i+1] = prefixlevels[i]+levels[i];
        }


        long long mx = 0;
        for (long long i = 0; i < n; i++) {
            mx = max((upper_bound(begin(prefixlevels), end(prefixlevels), n-i)-begin(prefixlevels)-1)*(st[i]), mx);
            cout << (upper_bound(begin(prefixlevels), end(prefixlevels), n-i)-begin(prefixlevels)-1)*(st[i]) << " ";
        }

        cout << mx << endl;

    }
}