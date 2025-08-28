#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        bool no = false;
        int pp, pc;
        for (int i = 0; i < n; i++) {
            int p, c; cin >> p >> c;

            if (i > 0 && (p < pp || c < pc)) no = true;
            if (i > 0 && c - pc > p - pp) no = true;
            if (c > p) no = true;

            pp = p;
            pc = c;
        }

        cout << (no ? "NO" : "YES") << endl;
    }
}