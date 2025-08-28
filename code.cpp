#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    

    while (t--) {
        string a; cin >> a;
        string b; cin >> b;
        vector<int> L;
        vector<int> R;

        int as = a.length();
        int bs = b.length();

        while (bs != as) {
            if (bs > as) {
                L.push_back(0);
                as++;
            } 
            else {
                R.push_back(0);
                bs++;
            } 
        }

        for (int i = 0; i < a.length(); i++) {
            L.push_back(a[i] - '0');
        }

        for (int i = 0; i < b.length(); i++) {
            R.push_back(b[i] - '0');
            //R[i] = b[i] - '0';
        }




        int n = L.size();
        vector<bool> bigger(n);

        int f = 0;
        for (int i = 0; i < L.size(); i++) {
            if (i == 0) {
                bigger[i] = R[i] > L[i];

                f += (R[i] - L[i]);
            } else {
                bigger[i] = R[i] > L[i] || bigger[i-1];

                int low = L[i];
                int high = R[i];

                if (bigger[i-1]) {
                    high = 9;
                    low = 0;
                }

                f += abs(high - low);
                //f += a;
            }
        }

        cout << f << endl;
    }

    return 0;
}