#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d; cin >> a >> b >> c >> d;



    vector<int> n(101);

    for (int i = a; i < b; i++) {
        n[i] = 1;
    }

    for (int i = c; i < d; i++) {
        n[i] = 1;
    }

    //for (auto& i : n) cout << i;

    cout << (accumulate(n.begin(), n.end(), 0));
}