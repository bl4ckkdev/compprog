#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        vector<int> ign;

        bool o = false;

        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == s[i+1]) {
                o = true;
                break;
            }
        }

        if (o) cout << 1 << endl;
        else cout << s.length() << endl;
    }
}