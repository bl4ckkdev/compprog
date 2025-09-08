#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string s; cin >> s;

        map<string, pair<int, int>> m;
        for (int i = 0; i < n-1; i++) {
            string so = ""; so = (so + s[i]) + s[i+1];

            if (m[so].first == 0 || i-m[so].second > 1) {
                if (m[so].first == 0) m[so].second = i;
                m[so].first++;
            } 
        }

        bool cooked = true;

        for (auto& i : m) {
            if (i.second.first > 1) {
                cooked = false;
                break;
            }
        }

        cout << (cooked ? "NO\n" : "YES\n");
    }
}