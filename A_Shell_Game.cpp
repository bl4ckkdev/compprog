#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t; cin >> t;

    vector<int> b(3);
    b[t+1] = 1;

    for (int i = 0; i < 3; i++) {
        int l, r; cin >> l >> r;

        swap(b[l-1], b[r-1]);
    }

    for (int i = 0; i < 3; i++) {
        if (b[i] == 1) cout << i;
    }
}