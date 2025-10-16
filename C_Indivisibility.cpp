#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int nms = 0;

    nms += n/2;
    nms += n/3/2;
    int primes = n/log(n);
    cout << primes << " ";
    //nms += primes; 
    //nms += 

    cout << nms;
}