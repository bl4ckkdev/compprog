#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    while (t--) {
        int64_t n, m, k;

        cin >> n >> m >> k;
        int64_t l = 0, r = n*m;

        int64_t rows = 1;
        
        int64_t filled = 0;

        while (r-1 > l) {
            int64_t middle = l + (r-l)/2;

            if ((m / (middle + 1) * middle + m % (middle + 1)) * n >= k) {
                r = middle;
            } else l = middle;
        }

        cout << r << endl;
    }
}