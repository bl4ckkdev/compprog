#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;

    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
        string a; cin >> a;

        vs[i] = a;
    }

    vector<string> amp;
    
    for (int i = 0; i < n; i++) {
        string b = vs[i];
        string c = "";
        for (int j = 0; j < b.length(); j++) {
            for (int d = 0; d < k; d++) {
                c += b[j];
            }
        }

        for (int j = 0; j < k; j++) {
            amp.push_back(c);
        }
    }

    for (int i = 0; i < amp.size(); i++) {
        cout << amp[i] << endl;
    }
}