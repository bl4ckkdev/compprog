#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;

    vector<long long> a(n), b(n);

    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];

    
    //sort(begin(a), end(a), greater<long long>());
    sort(begin(b), end(b));

    vector<pair<long long, long long>> c(n);
    vector<long long> d(n);

    for (long long i = 0; i < n; i++) {
        c[i].first = a[i] * (i+1)*(n-i);
        c[i].second = i;
    }

    sort(begin(c), end(c), greater<pair<long long, long long>>());

    
    for (long long i = 0; i < n; i++) {
        d[c[i].second] = b[i];
    }

    /*for (auto& i : a) cout << i << " ";
    cout << endl;
    for (auto& i : d) cout << i << " ";
    cout << endl;*/

    //cout << endl;

    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        //out << (i+1)*(n-i) << " ";
        sum += a[i] * d[i] * (i+1)*(n-i);
    }

    cout << sum;
}