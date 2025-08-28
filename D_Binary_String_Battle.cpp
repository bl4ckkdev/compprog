#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        string s; cin >> s;

        int middle = n/2;

        if (n % 2 == 0) {
            if (s[n/2] == '1') middle = n/2;
            else middle = n/2-1;
        }

        int boones = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') boones++;
        }

        int leftl = k/2;
        for (int i = 0; i < n; i++) {
            if (i == middle || leftl == 0) {
                break;
            }

            if (s[i] == '1') {
                s[i] = '0';
                leftl--;
            }
        }

        int leftr = leftl + ceil((double)k/2);
        
        for (int i = n-1; i > 0; i--) {
            if (i == middle || leftr == 0) {
                break;
            }

            if (s[i] == '1') {
                s[i] = '0';
                leftr--;
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (leftr == 0) {
                break;
            }

            if (s[i] == '1') {
                s[i] = '0';
                leftr--;
            }
        }


        int zeros = 0;
        int ones = 0;
        int mxz = 0;
        int mxo = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeros++;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
        }
        
        //cout << s << endl;
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') prefix[i+1] = 1;
        }

        for (int i = 1; i <= n; i++) {
            prefix[i] += prefix[i-1];
        }

        bool cooked = true;

        for (auto& i : prefix) {
            //cout << i << " ";
        }

        //cout << endl;

        for (int i = 1; i <= n-k; i++) {
            if (ones + k - (prefix[i+k] - prefix[i-1]) > k) {
                cooked = false;
                break;
            }
        }

        //if (k == 1 && boones > 1) cooked = false;
        //if (ones == 0) cooked = true;

        cout << (cooked ? "Alice\n" : "Bob\n");
        //cout << s << endl;
    }
}