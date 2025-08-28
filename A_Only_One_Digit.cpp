#include <bits/stdc++.h>

using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string n; cin >> n;

        int min = 1001;
        for (int i = 0; i < n.length(); i++) {
            if (n[i] - '0' < min) min = n[i] - '0';
        }

        cout << min << endl;
    }
}