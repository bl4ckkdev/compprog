#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> freq(m+1);
        vector<vector<int>> nums(n);

        for (int i = 0; i < n; i++) {
            int l; cin >> l;

            for (int j = 0; j < l; j++) {
                int num; cin >> num;

                nums[i].push_back(num);
                freq[num]++;
            }
        }

        int c = 0, d = 0;
        for (int i = 0; i < n; i++) {
            bool b = 1;
            for (int j = 0; j < nums[i].size(); j++) {
                if (freq[nums[i][j]]>1) {
                    b = 1;
                    if (j == nums[i].size()-1) c++;
                } else {
                    d++;
                    b = 0;
                    break;
                }
            }
        }

        for (int i = 1; i < m+1; i++) {
            if (freq[i] == 0) c = 0;
        }

        cout << ((c>1) ? "YES" : "NO") << endl;
    }
}