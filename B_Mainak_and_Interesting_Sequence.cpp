#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        if (m/n == (double)m/n) {
            cout << "YES" << endl;

            for (int i = 0; i < n; i++) {
                cout << m/n << " ";
            }

            cout << endl;
        } else if (n>1 && n%2 == 1 && ((m-1)/n == (double)(m-1)/n) && (m-1)/n > 0) {
            cout << "YES" << endl;

            for (int i = 0; i < n; i++) {
                if (i == n-1) {
                    cout << (m/n + 1) << " ";
                }
                else cout << m/n << " ";
            }

            cout << endl;
        } else cout << "NO" << endl;
    }

    return 0;
}