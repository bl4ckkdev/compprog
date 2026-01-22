#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for (long long i = 0; i < n; i++) cin >> a[i];

    for (long long i = 0; i < n; i++) cin >> b[i];

    long long l = 0, r = n-1;

    vector<pair<long long, pair<long long, long long>>> moves;

    for (int i = 0; i < n; i++) {
        if (a[i]<b[i]) l = i;
    }


    while (l>=0) {
        while (a[l]<b[l]) {
            
            while (a[r]<=b[r]) {
                r--;
            } 
            
            //cout << r+1 << " ";

            long long al = a[l], ar = a[r];
            a[l] += min(b[l]-al, ar-b[r]);
            a[r] -= min(b[l]-al, ar-b[r]);

            //cout << a[l] << " " << a[r] << "| ";

            moves.push_back({l, {r, min(b[l]-al, ar-b[r])}});
        }

        l--;
    }

    cout << moves.size() << endl;

    for (long long i = 0; i < moves.size(); i++) {
        cout << moves[i].first+1 << " " << moves[i].second.first+1 << " " << moves[i].second.second << endl;
    }
}