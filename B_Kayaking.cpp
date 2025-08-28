#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> w(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    int mn = 1e6;
    int s = 0; 
    for (int i = 0; i < 2*n; i++) {
        for (int j = i+1; j < 2*n; j++) {
            for (int k = 0; k < 2*n; k++) {
                if (k == i) k++;
                if (k == j) k++;

                if (k >= 2*n) break;
                
                int n1 = w[k];

                k++;

                if (k == i) k++;
                if (k == j) k++;

                if (k >= 2*n) break;

                int n2 = w[k];

                //if (k >= 2*n) cout << "AAA";
                s += n2-n1;
            }

            //cout << s << " ";
            if (s < mn) mn = s;

            s = 0;
        }
    }

    cout << mn;
}