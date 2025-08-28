#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int n, k; cin >> k >> n;

    vector<vector<int>> perf(k, vector<int>(n));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> perf[i][j];
        }
    }

    int pairs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool cons = true;
            for (int c = 0; c < k; c++) {
                if (perf[c][i] < perf[c][j]) {
                    cons = false;
                    break;
                }
            }

            if (cons) pairs++;
        }
    }

    cout << pairs;
}