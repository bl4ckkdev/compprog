#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int al; cin >> al;
        string a; cin >> a;

        int bl; cin >> bl;

        string b; cin >> b;

        string ord; cin >> ord;

        string begin; string end;

        for (int i = 0; i < bl; i++) {
            if (ord[i] == 'D') end += b[i];
            else begin += b[i];
        }

        reverse(begin.begin(), begin.end());

        cout << (begin + a + end) << endl;
    }
}