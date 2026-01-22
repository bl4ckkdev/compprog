#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int> cells(n);

    cells[0] = 1;

    for (int i = 0; i < n; i++) {
        
            for (int j = 1; j <= k; j++) {
                if (i+j<n) {
                    cells[i+j] += cells[i];
                }
            }   
    }

    cout << cells[n-1];
}