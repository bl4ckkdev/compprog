#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string s; cin >> s;


        vector<int> ve;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {

                ve.push_back(i);
                s[i] = '*';
                s[i-1] = '*';
            }
        }

        for (int i = 0; i < ve.size(); i++) {
            int l = ve[i]-2, r = ve[i]+1;

            if (l<0) continue;

            while (l>= 0 && r < n) {
                while (l >= 0 && s[l] == '*') l--;
                while (r < n && s[r] == '*') r++;

                if (l<0 || r>=n) break;

                if (s[l] == s[r]) {
                    s[l] = '*';
                    s[r] = '*';

                    l--;
                    r++;
                } else break;
            }
        }

        bool isi = n > 1;
        for (int i = 1; i < n; i++) {
            isi &= s[i] == s[i-1];
        }

        cout << (isi ? "YES" : "NO") << endl;
    }
}