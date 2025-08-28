#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, s; cin >> n >> s;
        long long pool = 0;
        for (long long i = 0; i < n; i++) {
            long long vx, vy, x, y; cin >> vx >> vy >> x >> y;

            if (x + y == s || x + vx == y + vy) pool++;
        }

        cout << pool << endl;
    }
}