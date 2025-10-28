#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;

        bool same = 0;

        same = a == b && b == c && c == d;

        cout << (same ? "YES\n" : "NO\n");
    }
}