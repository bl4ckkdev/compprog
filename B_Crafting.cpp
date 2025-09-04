#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int m = 1e9+1, need = 0, out = -1;

        bool cooked = false;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                
                need = b[i] - a[i];

                if (out != -1) cooked = true;
                out = i;
            } else m = min(m, a[i]-b[i]);
        }

        if (cooked || m < need) cout << "NO\n";
        else cout << "YES\n";
    }
}