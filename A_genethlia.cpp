#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    set<string> a;
    for (int i = 0; i < n; i++) {
        string b; cin >> b;
        b = b.substr(0, 5);

        a.insert(b);
    }

    cout << (n == a.size() ? "NO" : "YES");
}