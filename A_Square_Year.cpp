#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        
        if (sqrt((double)n) == round(sqrt((double)n))) cout << (sqrt((double)n)) << " " << 0 << endl;
        else cout << -1 << endl;
    }
}