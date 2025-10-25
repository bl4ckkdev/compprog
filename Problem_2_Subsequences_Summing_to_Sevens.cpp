#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;

    vector<int> c(n);

    for (int i = 0; i < n; i++) cin >> c[i];

    vector<long long> prefix(n+1);

    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + c[i];

    long long mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((prefix[j+1]-prefix[i])%7==0) mx = max(mx, j-i+1LL);
        }
    }

    cout << mx;

}