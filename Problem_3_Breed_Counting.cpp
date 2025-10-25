#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    vector<int> a(n+1),b(n+1),c(n+1);

    for (int i = 0; i < n; i++) {
        a[i+1] = a[i];
        b[i+1] = b[i];
        c[i+1] = c[i];

        if (cows[i] == 1) a[i+1]++;
        else if (cows[i] == 2) b[i+1]++;
        else c[i+1]++;
    }

    while (q--) {
        int l, r; cin >> l >> r;

        cout << a[r]-a[l-1] << " " << b[r]-b[l-1] << " " << c[r]-c[l-1] << endl;
    }
}