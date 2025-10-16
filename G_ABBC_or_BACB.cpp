#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        int sz = s.length();
        int b = 0; vector<int> as;

        for (int i = 0; i < sz; i++) {
            if (s[i] == 'B') b++;
            else if ((i == 0 || s[i-1] == 'B') && s[i]=='A') as.push_back(1);
            else as.back()++;
        }

        sort(begin(as), end(as), greater<int>());

        int sum = 0;

        for (int i = 0; i < min((int)as.size(), b); i++) {
            sum += as[i];
        }

        cout << sum << endl;
    }
}