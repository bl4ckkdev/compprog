#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, s; cin >> n >> s;

    vector<long long> f(n);
    vector<long long> own(n);

    for (long long i = 0; i < n; i++) cin >> f[i];

    long long sum = accumulate(begin(f), end(f), 0);

    for (long long i = 0; i < n; i++) cin >> own[i];

    long long ownsum = accumulate(begin(own), end(own), 0);
    sort(begin(own), end(own));

    long long tr = -1;

    for (long long i = 0; i <= n; i++) {
        if (ownsum>sum) {
            tr = i;
            break;
        }

        if (i == n) break;

        ownsum -= own[i];
        ownsum += s;
    }

    cout << tr;
}