#include <bits/stdc++.h>

using namespace std;

vector<long long> ay;

long long ms = 20*1e9+1;

void csum(int i, long long suma, long long sumb) {
    long long a = suma+ay[i];
    long long b = sumb+ay[i];

    if (i == ay.size()-1LL) {
        if (abs(a-sumb)<ms) {
            ms = abs(a-sumb);
        }

        if (abs(suma-b)<ms) {
            ms = abs(suma-b);
        }

        return;
    }

    csum(i+1, a, sumb);
    csum(i+1, suma, b);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;

    ay = vector<long long>(n);

    for (long long i = 0; i < n; i++) {
        cin >> ay[i];
    }

    csum(0, 0, 0);

    cout << ms;
}