#include <bits/stdc++.h>

using namespace std;
int sum(int n) {
    return (n / 2) * (n/2+1) - ((n + 1) / 2) * ((n + 1) / 2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;

        cout << (sum(r) - sum(l-1)) << endl;
    }

}