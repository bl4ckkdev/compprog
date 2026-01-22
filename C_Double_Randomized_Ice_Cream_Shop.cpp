#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k; cin >> n >> k;

    vector<long long> a(k);
    vector<long long> b(k);

    for (long long i = 0; i < k; i++) cin >> a[i];
    for (long long i = 0; i < k; i++) cin >> b[i];

    set<long long> as, bs;

    for (long long i = 0; i < k; i++) {
        as.insert(a[i]);
        bs.insert(b[i]);
    }

    set<long long> boring;
    set<long long> ass, bss;
    for (long long i = 1; i <= n; i++) {
        bool isA = as.count(i), isB = bs.count(i);
        if (!isA && !isB) boring.insert(i);
        else {
            if (!isA) ass.insert(i);
            if (!isB) bss.insert(i);
        } 
    }

    //cout << ass.size() << " " << bss.size() << " " << boring.size() << endl;

    long long intr = ass.size()*(bss.size()+boring.size()) + bss.size()*boring.size() + boring.size()*(boring.size()-1);
    long long borings = boring.size();

    cout << intr << " " << borings;
}