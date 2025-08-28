#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; cin >> n >> k;


    long long ans = (max((long long)floor((n - n + k + 1LL) /2), 0LL));
    if (k <= n) ans = floor(k/2LL);
    //if (n == k) ans--;
    //cout << l << " " << r;
    cout << ans << endl;
}