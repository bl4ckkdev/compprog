#include <bits/stdc++.h>

using namespace std;
long long M = (1e9) + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;
        int n = s.length();

        long long moves = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0' && s[i] != '1') {
                moves++;
                break;
            } 
        }

        vector<long long> mods(max(n, 2));

        mods[0] = 1;
        mods[1] = 3;

        for (int i = 2; i < n; i++) {
            mods[i] = (((mods[i-1]) % M) * 2) % M;
        }

        for (int i = 0; i < n; i++) {
            s[i] = '0' + (s[i] - '0') % 2;
        }

        //cout << s << " ";
        
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '1') {
                moves += mods[(n-i)-1];
                //cout << mods[(n-i)-1] << " ";
                moves %= M;
            }
        }

        cout << moves%M << endl;
    }
}