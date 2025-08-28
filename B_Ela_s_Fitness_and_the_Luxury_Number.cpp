#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long l, r; cin >> l >> r;

        long long num = floor(sqrt(r));
        int count = 0;
        for (int i = l; i <= num; i++) {
            if (i*i / i) count++;
        }

        cout << count << endl;
    }
}