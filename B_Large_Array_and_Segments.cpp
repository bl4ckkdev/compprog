#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int64 n, k, x;
        cin >> n >> k >> x;
        vector<int64> a(n);
        int64 S = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            S += a[i];
        }

        int64 totalPossible = (int64)S * k;
        if (totalPossible < x) {
            cout << 0 << '\n';
            continue;
        }

        vector<int64> suff(n);
        suff[n-1] = a[n-1];
        for (int i = n - 2; i >= 0; --i) suff[i] = suff[i+1] + a[i];

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if ((int64)suff[i] >= x) {
                ans += k;
            } else {
                int64 need_num = (int64)x - suff[i];
                int64 need = (int64)((need_num + (int64)S - 1) / (int64)S);
                if (need <= k) ans += (k - need);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
