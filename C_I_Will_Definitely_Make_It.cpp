#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> towers(n);

        int height = -1;
        for (int i = 0; i < n; i++) {
            cin >> towers[i];

            if (i+1 == k) height = towers[i];
        }

        sort(towers.begin(), towers.end());

        int ki = -1;
        for (int i = 0; i < n; i++) {
            if (towers[i] == height) ki = i;
        }

        int water = 1;
        bool nah = false;
        
        for (int i = ki+1; i < n; i++) {
            if (towers[i] - height > height-water+1) {
                nah = true;
                break;
            } else {
                water += towers[i]-height;
                height = towers[i];
            }
        }

        if (nah) cout << "NO\n";
        else cout << "YES\n";
    }
}