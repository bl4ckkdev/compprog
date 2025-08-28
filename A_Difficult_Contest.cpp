#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        string els = "";
        int n = 0, f = 0, t = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') n++;
            else if (s[i] == 'F') f++;
            else if (s[i] == 'T') t++;
            else els += s[i];
        }

        for (int i = 0; i < t; i++) {
            cout << "T";
        }

        for (int i = 0; i < n; i++) {
            cout << "N";
        }

        for (int i = 0; i < f; i++) {
            cout << "F";
        }

        cout << els << endl;
    }
}