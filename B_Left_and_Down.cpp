#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
 
    while (t--) {
        long long x, y, k; cin >> x >> y >> k;

        long long cost = 0;

        //cout << "hello!" << endl;
        if (x / __gcd(x, y) <= k && y / __gcd(x, y) <= k) {
            cout << "1" << endl;
        } else cout << "2" << endl;
    }
}