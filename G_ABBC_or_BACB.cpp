#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        vector<int> counts;

        string s; cin >> s;
        int n; n = s.length();

        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                cnt++;
                if (i == n-1) counts.push_back(cnt);
            } else {
                counts.push_back(cnt);
                cnt = 1;
                if (i == n-1) counts.push_back(cnt);
            }
        }

        int sz = counts.size();
        int pts = 0;

        for (int i = sz-1; i >= 0; i--) {
            if (i-2>0) {
                if (counts[i-1] > counts[i]) {
                    pts += counts[i-1];
                    counts[i-1] = 1;
                } else {
                    pts += counts[i];
                    counts[i] = 1;
                }
            } else if (i+2 < sz) {
                if (counts[i+1] > counts[i]) {
                    pts += counts[i+1];
                    counts[i+1] = 1;
                } else {
                    pts += counts[i];
                    counts[i] = 1;
                }            
            } else {
                if (counts[i+2]>counts[i-2]) {

                } else {

                }
            }
        }

        cout << pts << endl;
    }
}