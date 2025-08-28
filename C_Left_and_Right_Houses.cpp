#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string s; cin >> s;

        int zeros = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
            else zeros++;
        }

        int zzeros = zeros, oones = ones;
        int iz = 0, io = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zzeros--;

            if (zzeros == zeros/2) iz = i;
        }

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') oones--;

            if (oones == ones/2) io = i;
        }

        cout << iz << " " << io << endl;
    }
}