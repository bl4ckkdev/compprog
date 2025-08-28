#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        vector<int> a(3, 0);
        int n; cin >> n;

        int moves = 0;

        while (a[0] != n || a[1] != n || a[2] != n) {
            for (int i = 0; i < 3; i++) {
                if (a[0] == n && a[1] == n && a[2] == n) break;

                int left = (i == 0 ? 1 : 0);
                int right = (i == 0 ? 2 : 1);
                
                if (i == 0) {
                    left = 1;
                    right = 2;
                }
                if (i == 1) {
                    left = 0;
                    right = 2;
                }
                if (i == 2) {
                    left = 0;
                    right = 1;
                }

                int minn = min(a[left], a[right]);
                a[i] = min(minn*2 + 1, n);

                moves++;
            }
        }

        cout << moves << endl;
    }
    
}