#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    vector<long long> deals(19);

    for (long long i = 0; i <= 18; i++) {
        deals[i] = pow(3, i+1) + i*pow(3, i-1);
    }

    while (t--) {
        long long n; cin >> n;

        long long i = 19;
        for (long long j = 0; j < 19; j++) {
            if (pow(3LL, j) > n) break;
            else i = j;
        }

        long long cost = 0;

        while (n > 0 && i >= 0) {
            long long p = (long long)pow(3LL, i);

            if (n<p) {
                i--;
                continue;
            } 

            if (n>=p) {
                cost += deals[i] * (n/p);

                n -= p * (n/p);
                //cout << deals[i];
                
            }
        }
        //cout << " ";
        cout << cost << endl;
    }
}