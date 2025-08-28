#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n >> x;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        bitset<32> ab(0), bb(0), cb(0);
        bitset<32> target(x);

        for (int i = 0; i < n; i++) {
            bitset<32> bit(a[i]);
            bool cooked = false;
            for (int j = 0; j < 32; j++) {
                if (bit[j] == 1 && target[j] == 0) {
                    cooked = true;
                    break;
                }
            }

            if (!cooked) ab |= bit;
            else break;
        }

        for (int i = 0; i < n; i++) {
            bitset<32> bit(b[i]);
            bool cooked = false;
            for (int j = 0; j < 32; j++) {
                if (bit[j] == 1 && target[j] == 0) {
                    cooked = true;
                    break;
                }
            }

            if (!cooked) bb |= bit;
            else break;
        }
        
        for (int i = 0; i < n; i++) {
            bitset<32> bit(c[i]);
            bool cooked = false;
            for (int j = 0; j < 32; j++) {
                if (bit[j] == 1 && target[j] == 0) {
                    cooked = true;
                    break;
                }
            }

            if (!cooked) cb |= bit;
            else break;
        }

        if ((ab | cb | bb) != target) {
            cout << "No\n";
        } else cout << "Yes\n";
    }
}