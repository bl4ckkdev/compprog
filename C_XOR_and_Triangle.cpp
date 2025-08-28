#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        bitset<32> a(n);

        bitset<32> b(n);

        int o = -1;
        for (int i = 0; i < 32; i++) {
            if (a[i] == 1) o = i;
        }

        bool on = false, ze = false;
        for (int i = 0; i < o; i++) {
            if (!ze && b[i] == 1) {
                ze = true;
                b[i] = 0;
            }

            else if (!on && b[i] == 0) {
                on = true;
                b[i] = 1;
            }
        }

        int au = a.to_ulong();
        int bu = b.to_ulong();

        //cout << au << " " << bu << " " << (au ^ bu) << endl;
        if (on && ze) {
            if (bu < n) {
                cout << bu << endl;
            } else if (au ^ bu < n) {
                cout << (au ^ bu) << endl;
            } else cout << -1 << endl;
            
        } else cout << -1 << endl;
    }
}