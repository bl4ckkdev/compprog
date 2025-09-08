#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long a, b, x, y; cin >> a >> b >> x >> y;

        if (a>b) {
            cout << ((a ^ 1) == b ? y : -1);
        } else {
            long long c, d;
            c = b - a;
            d = (b + 1 >> 1) - (a + 1 >> 1);

            cout << (y > x ? c*x : (c-d)*x + d*y);
        }

        cout << endl;
    }
}