#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;


        bool isPrime = true;

        

        for (int i = 2; i <= sqrt(n); i++) {
            if (n/(long double)i == n/i) {
                isPrime = false;
                break;
            }
        }

        if (n == 1 && k != 2) isPrime = false;
        if (n != 1 && k > 1) isPrime = false;
        

        cout << (isPrime ? "YES\n" : "NO\n");
    }
}