#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("cowtip.in", "r", stdin);
    //freopen("cowtip.out", "w", stdout);

    int n; cin >> n;

    vector<vector<bool>> e(n, vector<bool>(n));
    vector<vector<bool>> flipped(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char aoue; cin >> aoue;

            e[i][j] = (aoue - '0');
        }
    }

    bool flip = false;
    int op = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (e[i][j]) {
                
                for (int k = 0; k < n; k++) {
                    for (int h = 0; h < n; h++) {
                        if (k <= i && h <= j) {
                            e[k][h] = !e[k][h];
                        }
                    }
                }

                for (int k = 0; k < n; k++) {
                    for (int h = 0; h < n; h++) {
                        cout << e[k][h];
                    }
                    cout << endl;
                }
                cout << i << " " << j << endl;
                op++;
            }
        }
    }

    cout << op;
}