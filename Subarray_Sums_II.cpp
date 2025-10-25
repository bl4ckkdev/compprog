#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x; cin >> n >> x;

    vector<long long> nums(n);

    for (long long i = 0; i < n; i++) cin >> nums[i];
    
    vector<long long> prefix(n+1);

    for (long long i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

    map<long long, long long> noc;

    long long ways = 0;
    for (long long i = 1; i <= n; i++) {
        ways += noc[prefix[i]-x];

        if (prefix[i] == x) ways++;

        noc[prefix[i]]++;
    }

    cout << ways;
}