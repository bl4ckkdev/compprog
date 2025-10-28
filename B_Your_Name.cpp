#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        string a, b; cin >> a >> b;

        map<char, int> ba, bb;


        for (int i = 0; i < n; i++) {
            ba[a[i]]++;
            bb[b[i]]++;
        }

        bool same = true;
        for (char h = 'a'; h <= 'z'; h++) {
            if (ba[h] != bb[h]) {

                same = false;
                break;
            }
        }

        cout << (same ? "YES\n" : "NO\n");
    }
}