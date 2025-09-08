#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string a, b; cin >> a >> b;

        bool cooked = false;
        for (int i = 0; i < n; i++) {
            if (a[i] != '0') break;

            if (b[i] != '0') {
                cooked = true;
                break;
            }
        }

        cout << (cooked ? "NO\n" : "YES\n");
    }
}