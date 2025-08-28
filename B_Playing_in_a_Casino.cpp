#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> p(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> p[i][j];
        }

        long long pot = 0;
        for (int i = 0; i < m; i++) {
            vector<long long> t(n);
            long long sum = 0;

            for (int j = 0; j < n; j++) {
                t[j] = p[j][i];
                sum += p[j][i];
            }

            sort(begin(t), end(t));
            long long curr = 0;
            for (int j = 0; j < n; j++) {
                curr += t[j];
                pot += llabs(sum - curr - (n-1-j)*t[j]);
            }
        }

        cout << pot << endl;
    }
}