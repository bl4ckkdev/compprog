#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        string s; cin >> s;

        bool nah = true;

        if (k == 0) {
            for (int i = 0; i < n; i++) {
                if (s[i] != s[n-i-1]) {
                    //cout << s[i] << " " << s[n-i-1] << endl;
                    if (s[i] - '0' < s[n-i-1] - '0') nah = false;
                    break;
                }
            }
        } else if (k >= 1) {
            nah = false;
        }

        if (n == 1) nah = true;
        else if (s[0] < s[n-1]) nah = false;

        bool akh = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                akh = false;
                break;
            }
        }

        if (akh) nah = true;


        cout << (nah ? "NO\n" : "YES\n");
    }
}