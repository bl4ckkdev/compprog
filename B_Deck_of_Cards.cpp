#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        string act; cin >> act;

        long long l = 0, r = 0, q = 0;

        for (long long i = 0; i < k; i++) {
            if (act[i] == '0') l++;
            else if (act[i] == '1') r++;
            else {
                q++;
            }
        }

        //l += q/2;
       // r += q/2;
        //q = q%2;

        for (long long i = 0; i < l; i++) {
            cout << "-";
        }

        long long cnt = 0;
        cnt += l + r + q;

        bool b = false;
        for (long long i = 0; i < q; i++) {
            if (q == n-l-r) {
                cout << "-";
                b = true;
            } 
            else cout << "?";
        }

        for (long long i = 0; i < n-l-r-q*2; i++) {
            cout << "+";
        }

        if (!b) for (long long i = 0; i < q; i++) {
            if (cnt+i >= n) break;
            cout << "?";
        }

        for (long long i = 0; i < r; i++) {
            cout << "-";
        }

        cout << endl;
    }

}