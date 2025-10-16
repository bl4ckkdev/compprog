#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b; cin >> n >> a >> b;

    int mx = 0;
    for (int i = 0; i < a; ++i) {
        int as = a/(i+1);
        
        int bs = (n-i-1 == 0 ? 0 : b/(n-i-1));

        //cout << as << " " << bs << " ";
        //cout << endl;

        mx = max(mx, min(as, bs));
    }

    cout << mx;
}