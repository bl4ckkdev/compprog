#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m, p, q; cin >> n >> m >> p >> q;

        bool possible = true;

        if (n%p == 0 && q*(n/p) != m) {
            possible = false;
        }        

        cout << (possible ? "YES" : "NO") << endl;
    }
}