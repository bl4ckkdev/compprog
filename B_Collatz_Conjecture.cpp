#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int x, y, k; cin >> x >> y >> k;

        int ox = x;
        int op = 0;
        int a = x;
        x = ceil((long double)x / y)*y;
        op += a-x;

        if (op >= k) {
            x = ox+k;
        }
        else
        while (x % y == 0) {
            x /= y;

            if (x % y != 0) {
                ox = x;
                x = ceil((long double)x / y)*y;

                int oop = op;
                op += x-ox;
                cout << x << " " << op << "  ";

                if (op >= k) {
                    x = ox + k-oop;

                    break;
                }
            } 
        }

        cout << x << endl;
    }
}