#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    bool c = 0;

    for (int i = 1; i < 1e7; i++) {
        if (pow(n, 2LL) + pow(i, 2LL) == (long long)sqrt(pow(n, 2LL) + pow(i, 2LL)) * (long long)sqrt(pow(n, 2LL) + pow(i, 2LL))) {
            cout << i << " " << (long long)sqrt(pow(n, 2LL) + pow(i, 2LL));
            c = 1;
            break;
        }
    } 

    if (!c) cout << -1;
}