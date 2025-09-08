#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> freq(n+1);

        for (int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            ++freq[a]; ++freq[b];
        }

        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (freq[i] == 1) ++cnt;
        }

        cout << (cnt+1)/2 << endl;
    }
}