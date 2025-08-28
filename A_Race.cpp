#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long a, x, y; cin >> a >> x >> y;

        long long ad = min(abs(a - x), abs(a - y));
        long long bd = ((double)(x + y)/2 == (x + y) / 2 ? abs((x+y)/2-x) : abs((x+y)/2-x)+1);
        if (y==x+1) bd = 1;

        //cout << ((double)(x + y)/2 == (x + y) / 2) << endl;
        cout << (bd < ad ? "YES" : "NO") << endl;
    }
}