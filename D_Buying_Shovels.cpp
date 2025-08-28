#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        for (int i = k; i >= 1; i--) {
            if (n%i == 0) {
                cout << n/i << endl;
                break;
            }
        }
    }
}