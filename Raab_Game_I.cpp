#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, a, b; cin >> n >> a >> b;

        vector<int> ca(a+b), cb(a+b);

        for (int i = n-a-b; i < n; i++) {
            ca[i-a-b] = i;
        }
    }
}