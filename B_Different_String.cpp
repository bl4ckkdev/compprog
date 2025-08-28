#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        sort(s.begin(), s.end(), greater<int>());
        string t = s;

        sort(t.begin(), t.end());

        if (t == s) cout << "NO\n"; else cout << "YES\n" << t << endl;
    }
}