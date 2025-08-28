#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<vector<int>> students(n, vector<int>(5));

        vector<int> count(5);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> students[i][j];
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n; j++) {
                if (students[j][i] == 1) count[i]++;
            }
        }

        vector<int> days;
        set<int> studs;


        bool cooked = true;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i != j && count[i] >= n/2 && count[j] >= n/2) {
                    set<int> h;

                    for (int k = 0; k < n; k++) {
                        if (students[k][i] == 1) h.insert(k);
                    }

                    for (int k = 0; k < n; k++) {
                        if (students[k][j] == 1) h.insert(k);
                    }

                    if (h.size()>=n) cooked = false;
                }

                if (!cooked) break;
            }
            if (!cooked) break;
        }

        cout << (cooked ? "NO\n" : "YES\n");
    }
}