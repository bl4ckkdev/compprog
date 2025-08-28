#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> nems = a;

        bool s = true;
        for (int i = 1; i < n; i++) {
            if (nems[i]<nems[i-1]) {
                s = false;
                break;
            }
        }

        if (s) cout << "NO\n";
        else {
            cout << "YES\n" << 2 << endl;

            for (int i = 0; i < n; i++) {
                bool br = false;
                for (int j = i+1; j < n; j++) {
                    if (nems[i]>nems[j]) {
                        cout << nems[i] << " " << nems[j] << endl;
                        br = true;
                        break;
                    }
                }
                if (br) break;
            }
        } 
    }
}