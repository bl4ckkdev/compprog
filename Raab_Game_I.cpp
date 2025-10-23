#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, a, b; cin >> n >> a >> b;

        int id = n-a-b;

        vector<int> aa(n);
        iota(begin(aa),end(aa), 1);

        vector<int> bb(n, -1);

        if (a+b>n) {
            cout << "NO\n";
            continue;
        }

        int count = 1;
        for (int i = 0; i < id; i++) {
            bb[i] = count;
            count++;
        }

        for (int i = n-a; i<n; i++) {
            bb[i] = count;
            count++;
        }

        for (int i = id; i<=n-a-1; i++) {
            bb[i] = count;
            count++;
        }

        int sca = 0, scb = 0;
        for (int i = 0; i < n; i++) {
            if (aa[i]>bb[i]) sca++;
            else if (bb[i]>aa[i]) scb++;
        }

        if (sca != a || scb != b) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << aa[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << bb[i] << " ";
            }

            cout << endl;
        }

    }
}