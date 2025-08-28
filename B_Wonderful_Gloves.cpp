#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        vector<long long> l(n), r(n);

        for (long long i = 0; i < n; i++) {
            cin >> l[i];
        }

        for (long long i = 0; i < n; i++) {
            cin >> r[i];
        }

        long long sum = 0;
        vector<long long> leftover;
        for (long long i = 0; i < n; i++) {
            if (l[i]>=r[i]) {
                sum += l[i];
                leftover.push_back(r[i]);
            } 
            else if (l[i]<r[i]) {
                sum += r[i];
                leftover.push_back(l[i]);
            } 
        }


        sort(leftover.begin(), leftover.end(), greater<long long>());

        for (long long i = 0; i < k; i++) {
            if (i != k-1) sum += leftover[i];
            else sum++;
        }

        cout << sum << endl;
    }
}