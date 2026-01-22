#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<string> ma;

    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        ma.push_back(a);
    }

    bool cooked = false;

    int idx = 0;

    for (auto& i : ma) {
        if (idx>0 && i == ma[idx-1]) cooked = true;

        for (int j = 1; j < i.length(); j++) {
            if (i[j] != i[j-1]) {
                cooked = true;
                break;
            }
        }

        idx++;
        if (cooked) break;
    }

    cout << (cooked ? "NO" : "YES") << endl;
}