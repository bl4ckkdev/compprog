#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, a, b; cin >> n >> a >> b;

        if (a % 2 == n % 2 && b % 2 == n % 2) {
            cout << "YES\n";
        } else if (b % 2 == n % 2 && b > a) cout << "YES\n";
        else cout << "NO\n";
    }
}